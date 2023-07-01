#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];

vector<int>adj_list[N];

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

int main(){

    int node, edge;
    cin>>node>>edge;


    while(edge--){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    bfs(1);

 return 0;
}
