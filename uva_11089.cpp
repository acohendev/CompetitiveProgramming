#include <iostream>

using namespace std;
using ll = long long;


int FIB[46] = {0, 1, 2, 0};

int main ()
{
    ll T, N;

    for (int i = 3; i < 46; i++)
        FIB[i] = FIB[i-1] + FIB[i-2];

    cin >> T;

    while (T--)
    {
        cin >> N;

        int i = 45;
        while (FIB[i] > N) i--;

        while (i > 0)
        {
            if (N >= FIB[i])
            {
                N -= FIB[i];
                cout << '1';
            }
            else
            {
                cout << '0';
            }
            i--;
        }
        cout << '\n';
    }
    return 0;
}