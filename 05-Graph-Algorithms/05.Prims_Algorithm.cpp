#include <iostream>
#include <vector>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

ll prim(vector<vector<pair<int, int>>> &adj) {
    int n = adj.size();

    if (n == 0) return INF;

    vector<ll> key(n, INF);
    vector<bool> inMST(n, false);

    key[0] = 0;
    ll total = 0;

    for (int step = 0; step < n; step++) {
        int u = -1;

        for (int v = 0; v < n; v++) {
            if (!inMST[v] &&
                (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        if (u == -1 || key[u] == INF)
            return INF;

        inMST[u] = true;
        total += key[u];

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (!inMST[v] && w < key[v]) {
                key[v] = w;
            }
        }
    }

    return total;
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n <= 0 || m < 0) return 0;

    vector<vector<pair<int, int>>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= n || v < 0 || v >= n || w < 0)
            return 0;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    ll result = prim(adj);

    if (result == INF)
        cout << "No MST exists\n";
    else
        cout << "Prim MST Weight: " << result << '\n';

    return 0;
}
