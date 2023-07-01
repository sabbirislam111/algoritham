#include<bits/stdc++.h>
using namespace std;

int networkDelayTime(vector<vector<int>> times, int n, int k) {
    // create an adjacency list to store the graph
    map<int, vector<pair<int, int>>> graph;
    for (auto time : times) {
        int u = time[0], v = time[1], w = time[2];
        graph[u].push_back(make_pair(v, w));
    }

    // initialize the distance map to store the minimum distance to each node
    map<int, int> distance;
    for (int i = 1; i <= n; i++) {
        distance[i] = INT_MAX;
    }

    // initialize the priority queue for Dijkstra's algorithm
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, k));
    distance[k] = 0;

    // run Dijkstra's algorithm
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto edge : graph[u]) {
            int v = edge.first, w = edge.second;
            if (distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
                pq.push(make_pair(distance[v], v));
            }
        }
    }

    // find the maximum distance to any node
    int max_distance = 0;
    for (auto d : distance) {
        if (d.second == INT_MAX) {
            return -1; // not all nodes are reachable
        }
        max_distance = max(max_distance, d.second);
    }

    return max_distance;
}

int main() {
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4, k = 2;
    int min_time = networkDelayTime(times, n, k);
    cout << "Minimum time to reach all nodes: " << min_time << endl;
    return 0;
}


