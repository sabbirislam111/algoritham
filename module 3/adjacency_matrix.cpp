
#include <bits/stdc++.h>
using namespace std;

int main() {
    int nodes = 3; //O(1)
    vector<pair<int, int>>adj_list[nodes]; // O(1)

    // O(E * 2) = O(E) -> O(n^2)

//    adj_list[0] = {{2, 3}};
//    adj_list[1] = {{0, 2}};
//    adj_list[2] = {{1, 4}};

    adj_list[0].push_back({2, 3});
    adj_list[1].push_back({0, 2});
    adj_list[2].push_back({1, 4});


     for (int i = 0; i < nodes; i++){
        cout<<i<<"->";
        for (int j = 0; j < adj_list[i].size(); j++){
            cout<<adj_list[i][j].first<<" "<<adj_list[i][j].second;
        }
        cout<<endl;
    }
    return 0;
}

