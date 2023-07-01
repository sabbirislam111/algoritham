#include<bits/stdc++.h>
using namespace std;


int main(){
const int N = 1e5;
const int INF = 1e9;
int dp[N];
int h[N];


int n, k;
cin>>n>>k;

for(int i = 1; i <= n; i++){
    cin>>h[i];
}
// base case

dp[1] = 0;
for(int i = 2; i <=n; i++){
    dp[i] = INF;

    for(int j= 1; j <=k; j++){

        // corner case
        if(i - j <= 0) break;
        int candidate_ans = dp[i - j] + abs(h[i] - h[i - j]);
        dp[i] = min(dp[i], candidate_ans);
    }

}
cout<<dp[n];




 return 0;
}
