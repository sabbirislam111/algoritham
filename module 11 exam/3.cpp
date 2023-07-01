#include<bits/stdc++.h>
using namespace std;

const int N = 2e5;
vector<int>adj_list[N];
int visited[N];



bool detect_cycle(int src){
    queue<int>q;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()){
        int head = q.front();
        q.pop();
        for(int adj_node: adj_list[head])
        {
         if(visited[adj_node] == 0){
            visited[adj_node] = 1;
            q.push(adj_node);
         }
         else if(visited[adj_node] == 2){
            return true;
         }

        }
        visited[src] = 2;
        return false;
    }



}



int main(){

    int nodes, edges;
    cin>>nodes>>edges;

    while(edges--){
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

    // print vector
//    for(int i = 0; i < nodes; i++){
//            cout<<i<<"->";
//        for(int element: adj_list[i]){
//            cout<<element<<" ";
//        }
//        cout<<endl;
//    }







 return 0;
}
