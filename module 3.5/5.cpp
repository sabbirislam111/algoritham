#include<bits/stdc++.h>
using namespace std;

int main() {

      int n = 4;
    vector<vector<int>> adjacencyMatrix(n, vector<int>(n, 0)); // initialize with zeros

    // add edges using a loop over a vector of (source, target) pairs

    vector<pair<int, int>> edges {{0, 1}, {1, 0}, {1, 2}, {1, 3}, {2, 0}, {2, 3}};
    for (auto [u, v] : edges) {
        adjacencyMatrix[u][v] = 1;
    }
    cout << "Edge from 0 to 1: " << adjacencyMatrix[0][1] << endl;
    cout << "No edge from 0 to 3: " << adjacencyMatrix[0][3] << endl;

    for(int i = 0; i < adjacencyMatrix.size(); i++){
            for(int j = 0; j < adjacencyMatrix.size(); j++){
                cout<<adjacencyMatrix[i][j]<<" ";
            }
            cout<<endl;
       // cout<<adjacencyMatrix[i][0]<<" "<<adjacencyMatrix[i][1]<<endl;
    }

    return 0;
}

