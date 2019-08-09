#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

struct pair_hash
{
    size_t operator() (const pair<int, int>& val_idx) const
    {
        return hash<int>()(val_idx.first);
    }
};

struct pair_cmp
{
    bool operator() (pair<int, int> const& p1, pair<int, int> const& p2) const
    {
        return p1.first == p2.first;
    }
};

int main ()
{
    int C;
    int N;
    int n;
    int id;
    int best_len = 0; 
    vector<int> snowflakes;
    unordered_set<pair<int, int>, pair_hash, pair_cmp> seen;
    
    cin >> C;

    while (C--)
    {
        best_len = 0;
        snowflakes.clear();
        seen.clear();
        cin >> N;
        n = N;

        while (N--)
        {
            cin >> id;

            snowflakes.push_back(id);
        }

        int start = 0;

        for (int itr = 0; itr < n; itr++)
        {
            pair<int, int> val_idx(snowflakes[itr], itr);
            auto found = seen.find(val_idx);
            if (found != seen.end())
            {
                start = found->second + 1;
                itr = start;
                val_idx = pair<int, int>(snowflakes[start], start);
                seen.clear();
            }
            seen.insert(val_idx);
            best_len = max (best_len, itr - start + 1);
        }

        cout << best_len << endl;
    }
}