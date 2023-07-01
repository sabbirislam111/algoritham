#include<bits/stdc++.h>
using namespace std;



vector<long long int> adj[100005];
long long int indegree[100001];

void bfs(int n) {
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    if (!q.empty()) {
        vector<int> v;
        while (!q.empty()) {
            int curr = q.front();
            v.push_back(curr);
            q.pop();
            for (int ele:adj[curr]) {
                indegree[ele]--;
                if (indegree[ele] == 0)
                    q.push(ele);
            }
        }
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (indegree[i] != 0) {
                cout << "IMPOSSIBLE"<<endl;
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i] << " ";
            }
        }
    } else cout << "IMPOSSIBLE"<<endl;
}

int main() {

    long long int n, m, a, b;
    cin >> n >> m;
    while (m--) {
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    bfs(n);
}
