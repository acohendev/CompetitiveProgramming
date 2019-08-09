#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

#define MAX(a , b) (a > b) ? a : b

ll gcd(ll u, ll v)
{
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do {
        v >>= __builtin_ctz(v);
        if (u > v) {
            ll t = v;
            v = u;
            u = t;
        }  
        v = v - u;
    } while (v != 0);
    return u << shift;
}


int main ()
{
    int t, c;
    vector<ll> a(11, 0);

    cin >> t;
    
    while (t--)
    {
        cin >> c;
        int countdown = c;
        ll global_gcd = 0;
        ll cur_sum = 0;
        ll max_a10 = 0;
        while (c--)
        {
            cin>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]>>a[10];
            max_a10 = MAX (max_a10, a[10]);
            cur_sum = a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]-a[10];
            if (global_gcd == 1) break;
            global_gcd = gcd (cur_sum, global_gcd);

            if (cur_sum == 0) countdown--;
        }

        if (global_gcd <= max_a10 || countdown == 0) cout << "impossible" << endl;
        else cout << global_gcd << endl;
    }

    return 0;
}