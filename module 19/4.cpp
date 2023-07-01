#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int N = 1e5 + 5;
int n, m, k;
vector<int> adj[N];
int timestamp[N];

void bfs(vector<int> &start) {
    queue<int> q;
    for (auto v : start) {
        q.push(v);
        timestamp[v] = 0;
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : adj[u]) {
            if (timestamp[v] == -1) {
                timestamp[v] = timestamp[u] + 1; //max(timestamp[v], timestamp[u] + 1);
                q.push(v);
            }
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> k;
    vector<int> start;
    for (int i = 0; i < k; i++) {
        int v;
        cin >> v;
        start.push_back(v);
    }
    //fill(timestamp, timestamp + n + 1, -1);
    for(int i = 1; i <= n; i++){
        timestamp[i] = -1;
    }

    bfs(start);
    int last_vertex = 1;
    int last_time = timestamp[1];
    for (int i = 2; i <= n; i++) {
        if (timestamp[i] > last_time) {
            last_time = timestamp[i];
            last_vertex = i;
        }
    }
    cout << last_time << endl;
    cout << last_vertex << endl;
    return 0;
}
