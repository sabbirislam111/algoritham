#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n, m, cost[105], dist[105];
vector<int> adj[105];
bool visited[105];

void dijkstra() {
    for (int i = n; i >= 1; i--) {
        dist[i] = INF;
    }
    dist[1] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, 1});

    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int u = p.second;
        if (visited[u]) continue;
        visited[u] = true;

        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] > dist[u] + cost[u]) {
                dist[v] = dist[u] + cost[u];
                q.push({dist[v], v});
            }
        }
    }
}




int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dijkstra();
    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[n] << endl;
    }
    return 0;
}

