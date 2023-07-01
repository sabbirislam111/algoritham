#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int adj_matrix[n][n];
    bool isSimple = true;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           cin>>adj_matrix[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (adj_matrix[i][i] == 1) {
                isSimple = false;
                break;
            }
            if (adj_matrix[i][j] > 1) {
                isSimple = false;
                break;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
           if(adj_matrix[i][j] !=  adj_matrix[j][i]){
             isSimple = false;
           }
        }
    }

    if(isSimple){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}

