#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

// n - # lakes
// m - # days
// array of lake indexs of size m

using namespace std;

int main ()
{
    int Z, n, m;

    cin >> Z;

    while (Z--)
    {
        cin >> n;
        cin >> m;

        vector<int> lakes(n, -1);
        vector<int> days(m, 0);
        vector<int> l(m, 0);
        unordered_set< pair<int, int> > available_zeroes;
        int zeroes = 0;
        string res("YES");
        
        for (int i = 0; i < m; i++) cin >> days[i];

        for (int i = 0; i < m; i++)
        {
            if (days[i] == 0)
            {
                l[zeroes] = 0;
                available_zeroes.insert(make_pair(i , zeroes));
                zeroes++;
            }
            else
            {
                
            }
        }

        
        cout << res << endl;
        if (res == "YES")
        {
            for (int i = 0; i < l_max_size; i++)
            {
                if (i > 0) cout << ' ';

                if (i < l.size()) 
                    cout << l[i];
                else
                    cout << '0';
            }
            cout << endl;
        }
    }

}