#include<bits/stdc++.h>

using namespace std;

double distance(double x1, double y1, double r1, double x2, double y2, double r2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool overlap(double x1, double y1, double r1, double x2, double y2, double r2) {
    //return distance(x1, y1, r1, x2, y2, r2) <= r1 + r2;
    if(distance(x1, y1, r1, x2, y2, r2) <= r1 + r2){
        return distance(x1, y1, r1, x2, y2, r2);
    }
}

void add_edge(vector<vector<int>>& adj_list, int u, int v) {
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}

void dfs(vector<vector<int>>& adj_list, vector<bool>& visited, int u) {
    visited[u] = true;
    for (int v : adj_list[u]) {
        if (!visited[v]) {
            dfs(adj_list, visited, v);
        }
    }
}

int count_circle_groups(vector<double>& x, vector<double>& y, vector<double>& r) {
    int n = x.size();
    vector<vector<int>> adj_list(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (overlap(x[i], y[i], r[i], x[j], y[j], r[j])) {
                add_edge(adj_list, i, j);
            }
        }
    }
    vector<bool> visited(n, false);
    int count = 0;
    for (int u = 0; u < n; u++) {
        if (!visited[u]) {
            dfs(adj_list, visited, u);
            count++;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector<double> x(n), y(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }
    int count = count_circle_groups(x, y, r);
    cout << count << endl;
    return 0;
}
