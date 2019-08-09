#include <iostream>
#include <bitset>
#include <unordered_set>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;

#define MAX_DIST 1000000

ll powmodn(ll a, ll q, ll n){
    ll res = 1;
    while(q){
        if (q%2) res = (res * a) % n;
        a = (a * a) % n;
        q >>= 1;
    }
    return res;
}

bool MR(ll n, int k=5){
    if(n==1 || n==4)
        return false;
    if(n==2 || n==3)
        return true;
    ll m = n - 1;
    int r = 0;
    while (m%2 == 0){
        m >>= 1;
        r+=1;
    }
    /* !!! Deterministic version for n<2^64 !!! */
    //    int dtrm_set[12] = {2,3,5,7,11,13,17,19,23,29,31,37};
    //    for(ll a: dtrm_set){
    //        if(a >= n) break;
    /* !!! End of deterministic version !!! */

    /* !!! Probablistic version !!! */
    while(k--){
        ll a = rand() % (n-4) + 2;
        /* !!! end of probablisitic version !!! */
        a = powmodn(a,m,n);
        if(a==1) continue;
        int i = r;
        while(i-- && a != n-1){
            a = (a*a)%n;
            if(a == 1) return false;
        }
        if(i == -1) return false;
    }
    return true;
}

int main ()
{
    ll L, U, C1, C2, D1, D2, last_prime;

    while (cin >> L >> U)
    {
        C1 = 0; C2 = MAX_DIST; 
        D1 = 0; D2 = 0;
        last_prime = -1;


        for (ll i = L; i <= U; i++)
        {
            if (MR(i))
            {
                if (last_prime != -1)
                {
                    if (i - last_prime < C2 - C1)
                    {
                        C1 = last_prime;
                        C2 = i;
                    }

                    if (i - last_prime > D2 - D1)
                    {
                        D1 = last_prime;
                        D2 = i;
                    }
                }

                last_prime = i;
            }
        }
        if (C1 == 0)
            cout << "There are no adjacent primes." << endl;
        else
            cout << C1 << "," << C2 << " are closest, " << D1 << "," << D2 << " are most distant."  << endl;
    }
    return 0;
}