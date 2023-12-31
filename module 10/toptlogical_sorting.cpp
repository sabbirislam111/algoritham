#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];

stack<int>node_stack;

void dfs(int node){
    visited[node] =1;
    for(int adj_node: adj_list[node]){
        if(visited[adj_node] == 0){
            dfs(adj_node);
        }
    }
    node_stack.push(node);

}



int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    for(int i = 0; i < edges; i++){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
    }

    for(int i = 0; i < nodes; i++){
         if(visited[i] == 0){
            dfs(i);
         }
    }
    while(!node_stack.empty()){
        cout<<node_stack.top()<<" ";
        node_stack.pop();
    }



 return 0;
}

