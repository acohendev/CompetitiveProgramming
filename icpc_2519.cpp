#include <iostream>
#include <vector>
#include <cmath>
#include <tuple>
#include <unordered_map>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

bool cmp (tuple<double, int, int>& br1, tuple<double, int, int>& br2)
{
    return get<0>(br1) < get<0>(br2) || (get<0>(br1) == get<0>(br2) && get<1>(br1) < get<1>(br2));
}
int main ()
{
    int i_case = 1;
    bool not_first = false;
    
    while (true)
    {
        if (not_first) cout << endl;
        not_first = true;

        int n, d;
        cin >> n;
        cin >> d;
        bool should_break = false;

        if (n == 0 && d == 0) break;

        vector< tuple<double, int, int> > brackets; // val, left or right, pnt id
        bool used[10000] = {0};

        for (int i = 0; i < n; i++)
        {
            double x, y;
            cin >> x;
            cin >> y;
            if (y > d)
            {
                cout << "Case " << i_case++ << ": " << -1 << endl;
                should_break = true;
                break;
            }
            brackets.push_back(make_tuple(x - sqrt(d*d - y*y), 0, i));
            brackets.push_back(make_tuple(x + sqrt(d*d - y*y), 1, i));
        }

        sort (brackets.begin(), brackets.end(), cmp);

        if (should_break) break;

        int counter = 0;
        vector<int> q;
        
        for (auto it = brackets.begin(); it != brackets.end(); it++)
        {
            if (used[get<2>(*it)]) continue;

            if (get<1>(*it) == 0)
                q.push_back(get<2>(*it));
            else 
            {
                counter++;
                for (auto id = q.begin(); id != q.end(); id++) used[*id] = true;
                q.clear();
            }
        }
        cout << "Case " << i_case++ << ": " << counter;
    }

    return 0;
}