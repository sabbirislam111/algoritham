#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5;
const int INF = 1e9;
int node, edge;

vector<pair<int, int>>adj_list[N];

int d[N], visited[N];


void dijkstra(int src){
    for(int i = 1; i <= node; i++){
        d[i] = INF;
    }
    d[src] = 0;

    for(int i = 0; i < node; i++){
        int seleceted_node = -1;
        for(int j = 0; j <= node; j++){
            if(visited[j] == 1) continue;
            if(seleceted_node == -1 || d[seleceted_node] > d[j]){
                seleceted_node = j;
            }
        }
        visited[seleceted_node] = -1;
        for(auto adj_entry: adj_list[seleceted_node]){
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[seleceted_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[seleceted_node] + edge_cst;
            }
        }
    }

}

int main(){


    cin>>node>>edge;

    for(int i = 0; i < edge; i++){
        int a, b, w;
        cin>>a>>b>>w;
        adj_list[a].push_back({b, w});
        adj_list[b].push_back({a, w});

    }

    int src = 1;
    dijkstra(src);

    for(int i = 0; i < node; i++){
        cout<<d[i]<<" ";
    }
    cout<<endl;





 return 0;
}
