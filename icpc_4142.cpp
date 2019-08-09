#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main ()
{
    int T;
    int D;
    string name;
    int L, H;
    int Q;
    int price;
    string result = "UNDETERMINED";
    bool found = false;
    bool not_first = false;
    vector< tuple<string, int, int> > db;

    cin >> T;

    while (T--)
    {
        if (not_first) cout << endl;
        not_first = true;

        cin >> D;

        for (auto i = 0; i < D; i++)
        {
            cin >> name;
            cin >> L; cin >> H;
            db.push_back(make_tuple (name, L, H));
        }

        cin >> Q;
        while (Q--)
        {
            cin >> price;

            result = "UNDETERMINED";
            found = false;

            for (auto item = db.begin(); item != db.end(); item++)
            {
                if (price >= get<1>(*item) && price <= get<2>(*item))
                {
                    if (found)
                    {
                        result = "UNDETERMINED";
                        break;
                    }
                    else
                    {
                        found = true; 
                        result = get<0>(*item);
                    }
                }
            }
            cout << result << endl;
        }
        db.clear();
    }
    return 0;
}