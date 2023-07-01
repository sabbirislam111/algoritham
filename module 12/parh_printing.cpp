#include<bits/stdc++.h>
using namespace std;
const int N = 2000;

vector<int> adj_list[N];
int visited[N], levele[N];
int parent[N];

void bfs(int src){
    queue<int>q;
    visited[src] = 1;
    levele[src] = 1;
    parent[src] = -1;

    q.push(src);

    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int adj_node: adj_list[head]){
            if(visited[adj_node] == 0){
                parent[adj_node] = head;
                visited[adj_node] = 1;
                levele[adj_node] = levele[head]+1;
                q.push(adj_node);
            }
        }
    }


}


int main(){

    int n, m;
    cin>>n>>m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int src_node = 1;
    bfs(src_node);

    int des_node = n;

    if(visited[des_node] == 0){
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
    }

    cout<<levele[des_node]<<" "<<endl;


    vector<int>path;
    int seleceted_node = des_node;

    while(true){
        path.push_back(seleceted_node);
        if(seleceted_node == src_node){
            break;

        }
        seleceted_node = parent[seleceted_node];

    }

    reverse(path.begin(), path.end());

    for(int node: path){
        cout<<node<<" ";
    }
    cout<<endl;





 return 0;
}
