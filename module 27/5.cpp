//#include <iostream>
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//const int N = 1e5 + 5;
//vector<int> g[N];
//int in[N];
//int ans = 0;
//
//void topological_sort(int n) {
//    queue<int> q;
//    for (int i = 1; i <= n; i++) {
//        if (in[i] == 0) {
//            q.push(i);
//        }
//    }
//    while (!q.empty()) {
//        int u = q.front();
//        q.pop();
//        ans = max(ans, (int)g[u].size());
//        for (int i = 0; i < g[u].size(); i++) {
//            int v = g[u][i];
//            in[v]--;
//            if (in[v] == 0) {
//                q.push(v);
//            }
//        }
//    }
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    for (int i = 1; i <= m; i++) {
//        int x, y;
//        cin >> x >> y;
//        g[x].push_back(y);
//        in[y]++;
//    }
//    topological_sort(n);
//    cout << ans << endl;
//    return 0;
//}




// C++ program to find the longest
// path in the DAG

#include <bits/stdc++.h>
using namespace std;

// Function to traverse the DAG
// and apply Dynamic Programming
// to find the longest path
void dfs(int node, vector<int> adj[], int dp[], bool vis[])
{
	// Mark as visited
	vis[node] = true;

	// Traverse for all its children
	for (int i = 0; i < adj[node].size(); i++) {

		// If not visited
		if (!vis[adj[node][i]])
			dfs(adj[node][i], adj, dp, vis);

		// Store the max of the paths
		dp[node] = max(dp[node], 1 + dp[adj[node][i]]);
	}
}

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
}

// Function that returns the longest path
int findLongestPath(vector<int> adj[], int n)
{
	// Dp array
	int dp[n + 1];
	memset(dp, 0, sizeof dp);

	// Visited array to know if the node
	// has been visited previously or not
	bool vis[n + 1];
	memset(vis, false, sizeof vis);

	// Call DFS for every unvisited vertex
	for (int i = 1; i <= n; i++) {
		if (!vis[i])
			dfs(i, adj, dp, vis);
	}

	int ans = 0;

	// Traverse and find the maximum of all dp[i]
	for (int i = 1; i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	return ans;
}

// Driver Code
int main()
{
	int n, m;
	cin>>n>>m;
	vector<int> adj[n + 1];

	for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        addEdge(adj, u, v);
	}

	cout << findLongestPath(adj, n);
	return 0;
}
