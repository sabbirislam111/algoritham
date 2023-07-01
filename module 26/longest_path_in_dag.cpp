#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>adj_list[N];
int dp[N];
int root, des;


int longest_path(int node){
    // base case
    if(node == root) {
        return 0;
    }

    if(dp[node] != -1){
        return dp[node];
    }

    int ans = 0;
    for(int adj_node:adj_list[node]){
        int parent_distance = longest_path(adj_node);
        ans = max(ans, parent_distance);
    }
    ans++;
    dp[node] = ans;
    return ans;
}


int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0; i < m; i++){
        int u, v;
        cin>>u>>v;
        adj_list[v].push_back(u);
    }

    for(int i = 0; i <=n; i++){
        dp[i] = -1;
    }



    cin>>root>>des;

    cout<<longest_path(des)<<endl;







 return 0;
}
