#include<bits/stdc++.h>
using namespace std;


const int N = 105; // number of nodes
vector<int> adj[N]; // adjacency list
int visited[N];
int dist[N]; // distance from the source
int parent[N]; // parent of each node
int maxDist; // max distance from the source
vector<int> longestPath; // longest path


void dfs(int u, int p, int d) {
    parent[u] = p;
    dist[u] = d;

    for (int v : adj[u]) {
        if (dist[v] == -1) {
            dfs(v, u, d + 1);
            if (dist[v] > maxDist) {
                maxDist = dist[v];
                longestPath.clear();
                longestPath.push_back(v);
            } else if (dist[v] == maxDist) {
                longestPath.push_back(v);
            }
        }
    }
}

void printPath(int u) {
    if (u == -1) return;
    printPath(parent[u]);
    cout << u << " ";
}


int main(){
    for(int i = 2; i < 102; i++){
        for(int j = 1; j < 102; j++){
            if(i*j < 101){
               adj[i].push_back(i*j);
            }

        }
    }
    // initialize dist and parent arrays
       for (int i = 2; i < N; i++) {
        dist[i] = -1;
        parent[i] = -1;
    }

    // perform DFS
    dfs(2, -1, 0); // assuming 0 is the source node

    // print the longest path
    for (int u : longestPath) {
        printPath(u);
        cout << endl;
    }
for(int i = 2; i < 101; i++){
        cout<<i<<" ";
    for(int node: adj[i]){
        cout<<node<<" ";
    }
    cout<<endl;
}

 return 0;
}

