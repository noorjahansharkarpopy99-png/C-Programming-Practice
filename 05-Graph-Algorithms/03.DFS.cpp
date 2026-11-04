#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>> &adj,
         vector<bool> &visited) {

    visited[u] = true;
    cout << u << " ";

    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v, adj, visited);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    if (n <= 0 || m < 0) return 0;

    vector<vector<int>> adj(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        if (u < 0 || u >= n || v < 0 || v >= n)
            return 0;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cin >> start;

    if (start < 0 || start >= n) return 0;

    vector<bool> visited(n, false);

    cout << "DFS Traversal: ";
    dfs(start, adj, visited);
    cout << '\n';

    return 0;
}
