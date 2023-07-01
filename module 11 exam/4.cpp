#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];
int levele[N];



int detect_cycle(int node){
    //cout<<node<<" ";
    visited[node] = 1;

    for(int adj_node:adj_list[node]){
        /*
            visited[adj_node] == 0 -> unexpected node | apply dfs
            visited[adj_node] == 1 -> "paused" node | cycle detected
            visited[adj_node] == 2 -> "done" node | continue
        */
        if(visited[adj_node] == 0){
            levele[adj_node] = levele[adj_node] + 1;
          int got_cycle = detect_cycle(adj_node);


           // return levele[adj_node];

        }
        else if(visited[adj_node] == 1 && levele[adj_node] >= 3){

            return levele[adj_node];
        }


    }
    visited[node] = 2;
    return false;


}




int main(){

    int nodes, edges;
    cin>>nodes>>edges;

    while(edges--){
        int a, b;
        cin>>a>>b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }

    int cycle_exists = 0;

    for(int i = 1; i <= nodes; i++){
        if(visited[i] == 0){
            int got_cycle = detect_cycle(i);
            //if(got_cycle){
                cout<<levele[got_cycle];
                break;
            //}
        }
    }

//    if(cycle_exists){
//        cout<<"Cycle Exists"<<endl;
//    }
//    else{
//        cout<<"Cycle not Exists"<<endl;
//
//    }


//    for(int i = 0; i < nodes; i++){
//            cout<<i<<"->";
//        for(int element: adj_list[i]){
//            cout<<element<<" ";
//        }
//        cout<<endl;
//    }







 return 0;
}
