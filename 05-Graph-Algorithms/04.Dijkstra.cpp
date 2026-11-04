#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

void dijkstra(vector<vector<pair<int, int>>> &adj,
              int source) {

    int n = adj.size();
    vector<ll> dist(n, INF);

    priority_queue<
        pair<ll, int>,
        vector<pair<ll, int>>,
        greater<pair<ll, int>>
    > pq;

    dist[source] = 0;
    pq.push({0, source});

    while (!pq.empty()) {
        ll d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d != dist[u]) continue;

        for (auto edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Shortest Distances:\n";

    for (int i = 0; i < n; i++) {
        cout << source << " -> " << i << ": ";

        if (dist[i] == INF)
            cout << "Unreachable\n";
        else
            cout << dist[i] << '\n';
    }
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

    int source;
    cin >> source;

    if (source < 0 || source >= n) return 0;

    dijkstra(adj, source);

    return 0;
}
