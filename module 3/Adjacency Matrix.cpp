
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes = 4;
    int arr[nodes][nodes];
    for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            arr[i][j] = 0;
        }
    }

    arr[0][1] = 1;

    arr[3][1] = 1;

     for (int i = 0; i < nodes; i++){
        for (int j = 0; j < nodes; j++){
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}
