#include<bits/stdc++.h>
using namespace std;

vector<int>adj_list[105];

int main(){
    for(int i = 2; i < 102; i++){
        for(int j = 1; j < 102; j++){
            if(i*j < 101){
               adj_list[i].push_back(i*j);
            }

        }
    }

for(int i = 2; i < 101; i++){
        cout<<i<<"->";
    for(int node: adj_list[i]){
        cout<<node<<" ";
    }
    cout<<endl;
}

 return 0;
}
