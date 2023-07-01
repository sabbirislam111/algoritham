// https://codeforces.com/problemset/problem/20/C
#include<bits/stdc++.h>
using namespace std;
const int N  = 1e5;
const long long INF = 1e18;
int node, edge;

vector<pair<int, int>>adj_list[N];

long long d[N];
int visited[N], parent[N];


void dijkstra(int src){
    for(int i = 1; i <= node; i++){
        d[i] = INF;
    }
    d[src] = 0;
    priority_queue<pair<long long, int>>pq;
    pq.push({0, src});

    for(int i = 0; i < node; i++){
//        int seleceted_node = -1;
//        for(int j = 0; j <= node; j++){
//            if(visited[j] == 1) continue;
//            if(seleceted_node == -1 || d[seleceted_node] > d[j]){
//                seleceted_node = j;
//            }
//        }
        pair<long long, int>head = pq.top();
        pq.pop();
        int selected_node = head.second;

        if(visited[selected_node]){
            continue;
        }


        visited[selected_node] = 1;
        for(auto adj_entry: adj_list[selected_node]){
            int adj_node = adj_entry.first;
            int edge_cst = adj_entry.second;

            if(d[selected_node] + edge_cst < d[adj_node]){
                d[adj_node] = d[selected_node] + edge_cst;
                parent[adj_node] = selected_node;
                pq.push({-d[selected_node], adj_node});
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

    //cout<<d[node]<<endl;

//    for(int i = 0; i < node; i++){
//        cout<<d[i]<<" ";
//    }
//    cout<<endl;


  int current_node = node;
  vector<int>path;

  while(true){
    path.push_back(current_node);
    if(current_node == src){
        break;
    }
    current_node = parent[current_node];
  }
  reverse(path.begin(), path.end());

  for(int node: path){
    cout<<node<<" ";
  }





 return 0;
}
