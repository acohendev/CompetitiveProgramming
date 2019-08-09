#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;
int main ()
{
    int cities;
    int boxes;
    int pop;
    vector<int> pops;
    int max_pop;
    bool not_first = false;

    while (true)
    {
        if (not_first) cout << endl;
        not_first = true;

        pops.clear();

        cin >> cities;
        cin >> boxes;
        if (cities == -1 && boxes == -1) break;

        for (int i = 0; i < cities; i++)
        {
            cin >> pop;
            pops.push_back(pop);
        }
        max_pop = *max_element(pops.begin(), pops.end());

        int low = 1;
        int high = max_pop;
        int mid;

        while (low < high)
        {
            mid = (low + high) / 2;

            int nr_req_boxes = 0;

            for (int cur_pop : pops)
                nr_req_boxes += cur_pop / mid + (cur_pop % mid > 0);
            
            if (nr_req_boxes > boxes)
                low = mid + 1;
            else
                high = mid;
        }
        cout << low;

    }
    return 0;
}
