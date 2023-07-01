#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];

vector<int>adj_list[N];

void dfs(int node){
    cout<<node<<" ";
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
    dfs(3);

 return 0;
}


/*
 6 6
 0 1
 1 2
 2 3
 1 5
 2 4
 5 4


*/

