#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

#define MAX_N 100

using namespace std;
using ii = pair<int, int>;
using vii = vector<ii>;
using vi = vector<int>;

// sort the friends according to the problems standarts.
// first = max contribution, second = order of appearance.
bool cmp(const ii& lhs, const ii& rhs)
{
    return (lhs.first == rhs.first) ? lhs.second > rhs.second :
                                      lhs.first < rhs.first;
}

int main ()
{
    int n, p, t, amount, total_amount;
    vii a;
    a.reserve(MAX_N);
    vi res(MAX_N, 0);

    cin >> t;
    while (t--)
    {
        cin >> p >> n;                  // p - price, n - # of friends
        a.clear();
        total_amount = 0;
        for (int i = 0; i < n; i++)     // read max amount for each friend
        {
            cin >> amount;
            total_amount += amount;
            a.emplace_back(amount, i);       // second is original index
        }

        if (total_amount < p)
        {
            cout << "IMPOSSIBLE\n";
            continue;
        }

        sort(a.begin(), a.begin() + n, cmp);
        
        while (p > 0)
        {
            for (int i = n - 1; i >= 0 && p > 0; i--)
            {
                if (a[i].first >0)
                {
                    a[i].first--;
                    p--;
                    res[a[i].second]++;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(i) cout << " ";
            cout << res[i];
        }
        cout << "\n";

        fill(res.begin(), res.end(), 0);
    }
    return 0;
}