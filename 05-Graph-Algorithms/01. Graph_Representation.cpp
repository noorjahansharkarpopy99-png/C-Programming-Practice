#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

using Graph = vector<vector<pair<int, int>>>;

void addEdge(Graph &adj, vector<vector<int>> &matrix,
             int u, int v, int w) {
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});

    matrix[u][v] = min(matrix[u][v], w);
    matrix[v][u] = min(matrix[v][u], w);
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n <= 0 || m < 0) return 0;

    Graph adj(n);
    const int INF = 1000000000;

    vector<vector<int>> matrix(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++)
        matrix[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        if (u < 0 || u >= n || v < 0 || v >= n || w < 0)
            return 0;

        addEdge(adj, matrix, u, v, w);
    }

    cout << "Adjacency List:\n";
    for (int i = 0; i < n; i++) {
        cout << i << ": ";
        for (auto edge : adj[i])
            cout << "(" << edge.first << ", "
                 << edge.second << ") ";
        cout << '\n';
    }

    cout << "\nAdjacency Matrix:\n";
    for (auto row : matrix) {
        for (int x : row) {
            if (x == INF) cout << "INF ";
            else cout << x << " ";
        }
        cout << '\n';
    }

    return 0;
}
