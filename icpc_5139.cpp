#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool lesser_than[26][26] = {0};
bool seen[26] = {0};

bool cmp (const char& lhs, const char& rhs)
{
    return lesser_than[lhs - 'A'][rhs - 'A'];
}

int main ()
{
    string cur_str;
    vector<string> strs;
    int strs_size = 0;
    vector<char> result;

    while (cin >> cur_str && cur_str != "#")
        strs.push_back(cur_str);

    strs_size = strs.size();
    for (int i = 0; i < strs_size - 1; i++)
    {
        for (int j = 0; j < min(strs[i].size(), strs[i+1].size()); j++)
        {
            char c1 = strs[i][j];
            char c2 = strs[i+1][j];
            if (c1 != c2)
            {
                seen[c1 - 'A'] = true;
                seen[c2 - 'A'] = true;
                lesser_than[c1 - 'A'][c2 - 'A'] = true;
                break;
            }
            // otherwise, keep sweeping the identical prefixes of the 
            // current 2 strings till you find different chars and mark
            // their relation.
        }
    }

    // after marking the direct relations from the strings, we need to 
    // update the transetive relations between each pair of chars

    for (int mid = 0; mid < 26; mid++)
        for (int left = 0; left < 26; left++)
            for (int right = 0 ; right < 26; right++)
                lesser_than[left][right] |= lesser_than[left][mid] && lesser_than[mid][right];

    for (int i = 0; i < 26; i++)
        if (seen[i]) result.push_back(i + 'A');

    sort(result.begin(), result.end(), cmp);

    for (char c : result) cout << c;
    cout << "\n";

    return 0;
}