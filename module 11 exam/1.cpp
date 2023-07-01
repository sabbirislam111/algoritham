#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];
int levele[N];

vector<int>adj_list[N];

void dfs(int src){
    visited[src] = 1;


        for(int adj_nodes: adj_list[src]){
            if(visited[adj_nodes] == 0){
                levele[adj_nodes] = levele[src] + 1;
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
    cout<<endl;
    for(int i = 0; i <= node; i++){
        cout<<"node: "<<i<<" level: "<<levele[i]<<endl;
    }

 return 0;
}
/*
5 6
0 1
1 2
1 4
2 3
2 5
4 5
*/
