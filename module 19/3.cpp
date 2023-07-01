#include <iostream>
#include <vector>
using namespace std;

vector<int> g[100005];

void addEdge(int u, int v) {
    g[u].push_back(v);
    g[v].push_back(u);
}

void vertex(int u) {
    if (g[u].empty()) {
        cout << endl;
    } else {
        for (int i = 0; i < g[u].size(); i++) {
            cout << g[u][i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int op, u, v;
        cin >> op >> u;
        if (op == 1) {
            cin >> v;
            addEdge(u, v);
        } else if (op == 2) {
            vertex(u);
        }
    }
    return 0;
}

