#include <iostream>
#include <vector>
#include <set>

using namespace std;
using ll = long long int;
using ii = pair<int, int>;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector< vector<int> >;
using vvii = vector< vector<ii> >;
using si = set<int>;
using vsi = vector<si>;

const int INF = 1e9;

/********** strongly connected components **********/

const int UNSEEN = -1;
const int SEEN = 1;

// DFS on digraph g from node u:
// visit a node only if it is mapped to the color UNSEEN,
// Mark all visited nodes in the color map using the given color.
// input: digraph (g), node (v), mapping:node->color (colorMap), color (color).
// output: DFS post-order (S), node coloring (colorMap).
void KosarajuDFS(const vvi& g, int u, vi& S, vi& colorMap, int color) {
    colorMap[u] = color;
    for (auto& v : g[u])
        if (colorMap[v] == UNSEEN)
            KosarajuDFS(g, v, S, colorMap, color);
    S.push_back(u);
}

// Compute the number of SCCs and maps nodes to their corresponding SCCs
// input: directed graph (g)
// output: the number of SCCs (return value), a mapping from node to SCC color (components)
int findSCC(const vvi& g, vi& components) {
    // first pass: record the `post-order' of original graph
    vi postOrder, seen;
    seen.assign(g.size(), UNSEEN);
    for (int i = 0; i < g.size(); ++i)
        if (seen[i] == UNSEEN)
            KosarajuDFS(g, i, postOrder, seen, SEEN);
    // second pass: explore the SCCs based on first pass result
    vvi reverse_g(g.size(),vi());
    for (int u=0; u<g.size(); u++) for (int v : g[u]) reverse_g[v].push_back(u);
    vi dummy;
    components.assign(g.size(), UNSEEN);
    int numSCC = 0;
    for (int i = (int)g.size()-1; i >= 0; --i)
        if (components[postOrder[i]] == UNSEEN)
            KosarajuDFS(reverse_g, postOrder[i], dummy, components, numSCC++);
    return numSCC;
}

// Computes the SCC graph of a given digraph
// input: directed graph (g)
// output: strongly connected components graph of g (sccg)
void findSCCgraph(const vvi& g, vsi& sccg) {
    vi component;
    int n = findSCC(g, component);
    sccg.assign(n, si());
    for (int u=0; u<g.size(); u++) for (int v: g[u]) // for every edge u->v
        if (component[u] != component[v])
            sccg[component[u]].insert(component[v]);
}

int main ()
{
    int T, n, m, s1, s2;

    cin >> T;
    while (T--)
    {
        cin >> n >> m;

        // build the implications graph
        vvi g(n, vi());

        while (m--)
        {
            cin >> s1 >> s2;
            g[s1 - 1].push_back(s2 - 1);
        }

        // build the SCC
        vsi scc;
        findSCCgraph(g, scc);

        if (scc.size() == 1)
        {
            cout << 0 << "\n";
            continue;
        }

        int nr_sources = 0;
        int nr_pits = 0;
        vi din(scc.size(), 0);

        for (si component : scc)
        {
            if (component.empty()) nr_pits++;
            else for (int v : component) din[v]++;
        }

        for (int count : din) if (count == 0) nr_sources++;

        cout << max(nr_sources, nr_pits) << "\n";

    }
    return 0;
}