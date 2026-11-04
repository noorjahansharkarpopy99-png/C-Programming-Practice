#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<vector<int>> &adj, int start) {
    vector<bool> visited(adj.size(), false);
    queue<int> q;

    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        cout << u << " ";

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    }
    cout << '\n';
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

    cout << "BFS Traversal: ";
    bfs(adj, start);

    return 0;
}
