#include<bits/stdc++.h>
using namespace std;




int main(){
    int node, edge;
    cin>>node>>edge;
    vector<int> lists[node];

    while(edge--){
        int a, b;
        cin>>a>>b;
        lists[a].push_back(b);
        //lists[b].push_back(a);
    }



    for(int i = 0; i < node; i++){
            cout<<i<<"->";
        for(int j = 0; j < lists[i].size(); j++){

            cout<<lists[i][j]<<" ";
        }
        cout<<endl;
    }


 return 0;
}
