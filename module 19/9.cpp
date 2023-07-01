#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int INF = 1e9;

int n, d, v, r, dist[105];
vector<pair<int, int>> trips[105];
bool visited[105];

void dijkstra() {
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[d] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, d});

    while (!q.empty()) {
        pair<int, int> p = q.top();
        q.pop();
        int u = p.second;
        if (visited[u]) continue;
        visited[u] = true;

        for (int i = 0; i < trips[u].size(); i++) {
            int v = trips[u][i].first;
            int t = trips[u][i].second;
            if (dist[v] > dist[u] + t) {
                dist[v] = dist[u] + t;
                q.push({dist[v], v});
            }
        }
    }
}

int main() {
    cin >> n >> d >> v >> r;
    for (int i = 0; i < r; i++) {
        int u, t, v, arrival;
        cin >> u >> t >> v >> arrival;
        trips[u].push_back({v, arrival - t});
    }
    dijkstra();
    if (dist[v] == INF) {
        cout << -1 << endl;
    } else {
        cout << dist[v] << endl;
    }
    return 0;
}

