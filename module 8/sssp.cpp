#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];
int levele[N];

vector<int>adj_list[N];

void bfs(int src){
    queue<int>q;
    visited[src] = 1;
    levele[src] = 0;
    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();
        cout<<head<<" ";

        for(int adj_nodes: adj_list[head]){
            if(visited[adj_nodes] == 0){
                visited[adj_nodes] = 1;
                levele[adj_nodes] = levele[head] + 1;
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
    bfs(0);
    cout<<endl;
    for(int i = 0; i < node; i++){
        cout<<"node: "<<i<<" level: "<<levele[i]<<endl;
    }

 return 0;
}
/*
5 6
0 2
1 2
1 4
2 3
2 5
4 5
*/
