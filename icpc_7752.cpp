#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;
using vi = vector<int>;
using vb = vector<bool>;

#define MAX_FIGURINES (100000 + 1)

vb isParent(MAX_FIGURINES, false);
vb seen(MAX_FIGURINES, false);
vi preconfig(MAX_FIGURINES, 0);
vi postconfig(MAX_FIGURINES, 0);

int main ()
{
    int n;

    while (cin >> n)
    {
        for (int i = 1; i <= n; i++) cin >> preconfig[i];
        for (int i = 1; i <= n; i++) cin >> postconfig[i];

        int total_ops = 0;

        fill(seen.begin(), seen.end(), false);
        for (int i = 1; i <= n; i++)
        {
            while (preconfig[i] && !seen[i])
            {
                seen[i] = true;
                total_ops++;
            }
        }

        fill(seen.begin(), seen.end(), false);
        for (int i = 1; i <= n; i++)
        {
            while (postconfig[i] && !seen[i])
            {
                seen[i] = true;
                total_ops++;
            }
        }

        fill(isParent.begin(), isParent.end(), false);
        for (int i = 1; i <=n; i++)
        {
            if (preconfig[i]) isParent[preconfig[i]] = true;
            if (postconfig[i]) isParent[postconfig[i]] = true;
        }

        for (int i = 1; i <= n; i++)
        {
            int j = i;
            if (isParent[j]) continue;

            while (preconfig[j] && preconfig[j] == postconfig[j])
            {
                total_ops -= 2; //unnecessary ops for collapse & rebuild
                j = preconfig[j];
            }
        }

        cout << total_ops << '\n';
    }

    return 0;
}