#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
vector<pair<int, int>> adj_list[N];
int adj_matrix[N][N];

void converListToMatrix(int n){
    for(int i = 0; i < n; i++){
        for(auto neighbor: adj_list[i]){
            int v = neighbor.first;
            int w = neighbor.second;
            adj_matrix[i][v] = w;
        }

    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout<<adj_matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main() {
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj_list[u].push_back({v, w});
    }

//    for(int u = 1; u <= n; u++) {
//        cout << u << "->";
//        for(auto neighbor : adj_list[u]) {
//            int v = neighbor.first;
//            int w = neighbor.second;
//            cout << "(" << v << "," << w << ")" << " ";
//        }
//        cout << endl;
//    }
    cout<<endl;
    converListToMatrix(n);
    return 0;
}

/*
input:-

5 4
1 2 5
1 3 6
2 4 2
3 5 10

*/
