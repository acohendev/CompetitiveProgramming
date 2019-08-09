#include <iostream>
#include <vector>

using namespace std;
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;

const int INF = 1e9;

/* **************************** Floyd-Warshall ****************************** */

// input: weighted directed graph (g)
// output: the pairwise distances (d)
void FloydWarshall(const vvii& g, vvi& d) {
    // initialize distances according to the graph edges
    d.assign(g.size(), vi(g.size(), INF));
    for (int u=0; u<g.size(); ++u) d[u][u] = 0;
    for (int u=0; u<g.size(); ++u) for (ii e: g[u]) {
        int v = e.first; int w = e.second;
        d[u][v] = min(d[u][v],w);
    }
    // relax distances using the Floyd-Warshall algorithm
    for (int k=0; k<g.size(); ++k)
        for (int u=0; u<g.size(); ++u)
            for (int v=0; v<g.size(); ++v)
                d[u][v] = min(d[u][v], d[u][k]+d[k][v]);
}
/* ************************************************************************** */

int main ()
{
    int cases, N, E, T, M, a, b, w, nr_mice;

    cin >> cases;
    while (cases--)
    {
        cin >> N >> E >> T >> M;

        vvii maze(N, vii());
        vvi distances(N, vi());

        while (M--)
        {
            cin >> a >> b >> w;
            maze[a - 1].emplace_back(b - 1, w);
        }

        FloydWarshall(maze, distances);
        nr_mice = 0;
        for (vi& cell : distances) nr_mice += (cell[E - 1] <= T);

        cout << nr_mice << ((cases) ? "\n\n" : "\n");
    }
    return 0;
}