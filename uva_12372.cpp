#include <iostream>

using namespace std;

int main ()
{
    long long nr_tests = 0;
    long long w, l, h;
    int test_idx = 1;

    cin >> nr_tests;

    while (nr_tests--)
    {
        cin >> l;
        cin >> w;
        cin >> h;

        if (l > 20 || w > 20 || h > 20)
            cout << "Case " << test_idx++ << ": bad" << endl;
        else
            cout << "Case " << test_idx++ << ": good" << endl;
    }

    return 0;
}