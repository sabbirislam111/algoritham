#include<bits/stdc++.h>
using namespace std;
const int N = 100;

vector<int>adj_list[N];
int parent[N];
int visited[N];


void bfs(int src){

    queue<int>q;
    q.push(src);
    visited[src] = 1;
    while(!q.empty()){
        int head = q.front();

        q.pop();
        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                q.push(adj_node);
                parent[adj_node] = head;
                cout<<head<<" "<<adj_node<<endl;
                visited[adj_node] = 1;
            }
        }

    }

}

int main(){

    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);

    }
cout<<endl<<endl;
bfs(1);






 return 0;
}
