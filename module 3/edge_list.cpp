
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes = 3; //O(1)
    vector<vector<int> >edge_lost;

    edge_lost.push_back({0, 1});
    edge_lost.push_back({1, 2});
    edge_lost.push_back({2, 3});
    edge_lost.push_back({3, 4});

    for(int i = 0; i < edge_lost.size(); i++){
        cout<<edge_lost[i][0]<<" "<<edge_lost[i][1]<<endl;
    }


    return 0;
}

