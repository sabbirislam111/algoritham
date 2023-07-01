//
// => input a weighted graph as a adjacency matrix
// => all pair shortest distance
//
// Time complexity = O(v*3)
// Space complexity = O(v*2)
//
//
// - create a directed matrix "d" where d[i][j] = x where there is a directed edge
//    from node "i" to node "j" and the cost is 'x'
// - for all node "i" d[i][j] = 0;
// - for all nodes "i" and "j" where there is not any directed edge from "i" to "j"
//
//
//- for all nod "k"
//    - for all node "u"
//        - for all node "v"
//            - d[u][v] = min(d[u][v], d[u][k] + d[k][v])
//
//- output all pair shorted distance "d"

#include<bits/stdc++.h>
using namespace std;
int N = 1e3 + 3;
 int d[N][N];
 int INF = 1e9;


int main(){
    int n, m;
    cin>>n>>m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=n; j++){
            d[i][j] = INF;
        }
    }

    for(int i = 0; i <m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        d[u][v] = w;
    }
    for(int i = 1; i <= n; i++){
        d[i][i] = 0;
    }

    for(k = 1; k <= n; k++){
        for(int u = 1; u <= n; u++){
            for(int v = 1; v <= n; v++){
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
            }
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= n; j++){
            cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }


 return 0;
}




