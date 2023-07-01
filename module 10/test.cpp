

#include <bits/stdc++.h>
using namespace std;
const int N = 2000;
int adj_matrix[N][N];
int visited[N];
int node, edges;

void add_edge(int a, int b){
    adj_matrix[a][b] = 1;
    adj_matrix[b][a] = 1;
}

void bfs(int src){
    queue<int>q;
    q.push(src);
    visited[src] = 1;

    while(!q.empty()){
        int head = q.front();
        cout<<head<<" ";
        q.pop();
        for(int j = 0; j< edges; j++){
            if(adj_matrix[head][j]== 1 && visited[j] == 0){
                q.push(j);
                visited[j] = 1;
            }
        }

    }

}



int main(){

    cin>>node>>edges;


    add_edge(0, 1);
    add_edge(0, 2);
    add_edge(1, 3);
    add_edge(1, 4);

    for(int i = 0; i < node; i++)
    {
        for(int j = 0; j < edges; j++)
        {
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    bfs(1);


 return 0;
}
