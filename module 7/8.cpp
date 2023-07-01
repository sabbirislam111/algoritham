#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];

vector<int>adj_list[N];
int target_node = 5;

void bfs(int src){
    queue<int>q;
    visited[src] = 1;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();
        cout<<head<<" ";

        for(int adj_nodes: adj_list[head]){
            if(visited[adj_nodes] == 0){
                visited[adj_nodes] = 1;
                q.push(adj_nodes);
            }
        }
    }
}

void dfs(int node){
    cout<<node<<" ";
    if (node == target_node){
        bfs(node);
    }
    visited[node] = 1;

    for(int adj_nodes: adj_list[node]){
        if(visited[adj_nodes] == 0){
            dfs(adj_nodes);
        }
    }
}

int main(){

    int node, edge;
    cin>>node>>edge;


    while(edge--){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    dfs(0);

 return 0;
}
