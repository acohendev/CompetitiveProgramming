#include <iostream>
#include <vector>

using namespace std;
using ll = long long int;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector< vector<int> >;
using vvii = vector< vector<ii> >;

const int INF = 1e9;


/********** Bellman-Ford **********/

// input: weighted directed graph (g), source node (s)
// output: is there a negative cycle in g? (return value), the distances from s (d)
// comment: the values in d are valid only if there is no negative cycle
bool BellmanFord(const vvii& g, int s, vi& d) {
    d.assign(g.size(), INF);
    d[s] = 0;
    bool changed = false;
    // V times
    for (int i = 0; i < g.size(); ++i) {
        changed = false;
        // go over all edges u->v with weight w
        for (int u = 0; u < g.size(); ++u) for (ii e : g[u]) {
            int v = e.first;
            int w = e.second;
            // relax the edge
            if (d[u] < INF && d[u]+w < d[v]) {
                d[v] = d[u]+w;
                changed = true;
            }
        }
    }
    // there is a negative cycle if there were changes in the last iteration
    return changed;
}


int main ()
{
    int W, H, G, E, x, y, xd, yd, T, time;

    while (cin >> W >> H && W != 0)
    {
        vvii graveyard(W * H, vii());
        vi times;
        times.reserve(W * H);
        vector<bool> gravestones(W * H, false);

        cin >> G;
        while (G--)
        {
            cin >> x >> y;
            gravestones[y * W + x] = true;
        }

        cin >> E;
        while (E--)
        {
            cin >> x >> y >> xd >> yd >> T;
            graveyard[y * W + x].push_back(make_pair(yd * W + xd, T));
        }

        for (int i = 0; i < W; i++)
        {
            for (int j = 0; j < H; j++)
            {
                if ((i == W - 1 && j == H - 1) || gravestones[j * W + i] || !graveyard[j * W + i].empty()) continue;

                if (i + 1 < W && !gravestones[j * W + i + 1]) 
                    graveyard[j * W + i].push_back(make_pair(j * W + i + 1, 1));

                if (i - 1 >= 0 && !gravestones[j * W + i - 1]) 
                    graveyard[j * W + i].push_back(make_pair(j * W + i - 1, 1));

                if (j + 1 < H && !gravestones[(j + 1) * W + i]) 
                    graveyard[j * W + i].push_back(make_pair((j + 1) * W + i, 1));

                if (j - 1 >= 0 && !gravestones[(j - 1)* W + i]) 
                    graveyard[j * W + i].push_back(make_pair((j - 1)* W + i, 1));
            }
        }

        if (BellmanFord(graveyard, 0, times))
            cout << "Never\n";
        else if ((time = times[times.size() - 1]) < INF)
            cout << time << "\n";
        else 
            cout << "Impossible\n";
    }
    return 0;
}