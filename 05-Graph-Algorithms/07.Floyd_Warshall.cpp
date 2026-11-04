#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using ll = long long;
const ll INF = (1LL << 60);

void floydWarshall(vector<vector<ll>> &dist) {
    int n = dist.size();

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (dist[i][k] != INF &&
                    dist[k][j] != INF) {

                    dist[i][j] = min(
                        dist[i][j],
                        dist[i][k] + dist[k][j]
                    );
                }
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n <= 0 || m < 0) return 0;

    vector<vector<ll>> dist(n, vector<ll>(n, INF));

    for (int i = 0; i < n; i++)
        dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= n || v < 0 || v >= n || w < 0)
            return 0;

        dist[u][v] = min(dist[u][v], (ll)w);
        dist[v][u] = min(dist[v][u], (ll)w);
    }

    floydWarshall(dist);

    cout << "Floyd-Warshall Distances:\n";

    for (auto row : dist) {
        for (ll x : row) {
            if (x == INF)
                cout << "INF ";
            else
                cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
