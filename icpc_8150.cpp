#include <iostream>

using namespace std;

int main ()
{
    int W;
    int N;

    while (cin >> W, cin >> N)
    {
        int l;
        int w;
        int S = 0;

        while (N--)
        {
            cin >> w;
            cin >> l;
            S += w * l;
        }
        cout << S / W << endl;
    }

    return 0;
}