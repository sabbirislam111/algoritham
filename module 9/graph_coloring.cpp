
/*
5 4
1 2
1 3
2 3
4 5


*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5;

int visited[N];
int color[N];

vector<int>adj_list[N];

bool dfs(int node){
    visited[node] = 1;

    for(int adj_nodes: adj_list[node]){
        if(visited[adj_nodes] == 0){
            //assign different color to adj_node
            if(color[node] == 1) color[adj_nodes] = 2;
            else color[adj_nodes] = 1;
            bool is_bicolorable = dfs(adj_nodes);
            if(!is_bicolorable){
                return false;
            }
        }
        else{
            // check if color is same or different
            if(color[node] == color[adj_nodes]){
                return false;
            }
        }
    }
    return true;
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

    bool is_bicolorable = true;
    for(int i = 0; i < node; i++){
        if(visited[i] == 0){
            color[i] = 1;
            bool ok = dfs(i);
            if(!ok){
                is_bicolorable = false;
                break;
            }
        }
    }

    if(!is_bicolorable){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i = 0; i < node; i++){
            cout<<color[i]<<" ";
        }
    }


 return 0;
}

