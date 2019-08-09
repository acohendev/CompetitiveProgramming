#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#include <string>

#define MAX_K 10000

class greater_triple;

using namespace std;
using ll = long long int;
using triple_t = tuple<ll, ll, ll>;
using minheap_triple_t = priority_queue<triple_t, vector<triple_t>, greater_triple>;

class greater_triple
{
    public:

    bool operator() (const triple_t& lhs, const triple_t& rhs) const
    {
        return (get<0>(lhs) == get<0>(rhs)) ? get<1>(lhs) > get<1>(rhs) : get<0>(lhs) > get<0>(rhs);
    }
};

int main ()
{
    int k, q_num, period;
    string instruct;
    minheap_triple_t queries; // each element: (period, Q_num, delta)

    while (cin >> instruct && instruct != "#")
    {
        cin >> q_num >> period;
        queries.emplace(period, q_num, period);
    }

    cin >> k;
    for (int i = 0; i < k; i++)
    {
        triple_t min_triple = queries.top();
        queries.pop();

        cout << get<1>(min_triple) << "\n";

        // rearrange the heap with the next time this query should print out
        get<0>(min_triple) += get<2>(min_triple); 
        queries.push(min_triple);
    }
    return 0;
}