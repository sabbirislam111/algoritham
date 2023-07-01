#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];

// it's a dfs
bool detect_cycle(int node){
    visited[node] = 1;

    for(int adj_node:adj_list[node]){
        /*
            visited[adj_node] == 0 -> unexpected node | apply dfs
            visited[adj_node] == 1 -> "paused" node | cycle detected
            visited[adj_node] == 2 -> "done" node | continue
        */
        if(visited[adj_node] == 0){
           bool got_cycle = detect_cycle(adj_node);
           if(got_cycle){
            return true;
           }
        }
        else if(visited[adj_node] == 1){
            return true;
        }


    }
    visited[node] = 2;
    return false;


}



int main(){
    int nodes, edges;
    cin>>nodes>>edges;

    for(int i = 0; i < edges; i++){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
    }

    bool cycle_exists = false;

    for(int i = 1; i <= nodes; i++){
        if(visited[i] == 0){
            bool got_cycle = detect_cycle(i);
            if(got_cycle){
                cycle_exists = true;
                break;
            }
        }
    }

    if(cycle_exists){
        cout<<"Cycle Exists"<<endl;
    }
    else{
        cout<<"Cycle not Exists"<<endl;
    }


 return 0;
}

