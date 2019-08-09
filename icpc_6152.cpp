#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main ()
{
    int C;
    string S;
    string T;
    int i = 1;

    cin >> C;

    while (C--)
    {
        int res = 0;
        int nr_1 = 0;
        int nr_0 = 0;

        cin >> S;
        cin >> T;

        if (count (S.begin(), S.end(), '1') > count (T.begin(), T.end(), '1'))
            res = -1;
        else
        {
            auto s = S.begin();
            auto t = T.begin();

            for (; s != S.end(); s++, t++)
            {
                if (*s != *t)
                {
                    if (*s == '1') nr_1++;
                    else if (*s == '0') nr_0++;
                    else res++; // char is '?'
                }
            }

            res += max (nr_1, nr_0);
        }
        cout << "Case " << i++ << ": " << res << endl;
    }
    return 0;
}