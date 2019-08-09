#include <cmath>
#include <unordered_set>
#include <iostream>

using namespace std;


#define DEGREE_DELTA 6


int Degree (int hour_hand, int minute_hand)
{
    int degree = DEGREE_DELTA * abs (hour_hand - minute_hand);
    return (degree > 180) ? 180 - degree : degree;
}


int main ()
{
    unordered_set<int>  degrees = {0};
    int                 degree  = 0;

    for (int hour_hand = 0; hour_hand < 60;  hour_hand++)
        for (int minute_hand = 0; minute_hand < 60; minute_hand += 12)
            degrees.insert(Degree(hour_hand, minute_hand));
    
    while (cin >> degree)
    {
        auto search = degrees.find(degree);
        if (search != degrees.end())
            cout << 'Y' << endl;
        else
            cout << 'N' << endl;
    }

    return 0;
}