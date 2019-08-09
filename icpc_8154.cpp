#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;

int main ()
{
    ll n, ww, wh, yw, yh, pw, ph;


    while (cin >> n)
    {
        vector<ll> A(n, 0);
        vector<ll> B(n, 0);
        ww = wh = yw = yh = pw = ph = 0;
        for (ll i = 0; i < n; i++) cin >> A[i];
        for (ll i = 0; i < n; i++) cin >> B[i];

        for (ll i = 0; i < n; i+=3)
        {
            ww += A[i];
            wh += B[i];
        }

        for (ll i = 1; i < n; i+=3)
        {
            yw += A[i];
            yh += B[i];
        }

        for (ll i = 2; i < n; i+=3)
        {
            pw += A[i];
            ph += B[i];
        }

        ll sw = ww*wh + yw*ph + pw*yh;
        ll sy = yw*yh + ww*ph + pw*wh;
        ll sp = pw*ph + ww*yh +yw*wh;

        cout << sp << " " << sy << " " << sw << "\n";
    }
    return 0;
}