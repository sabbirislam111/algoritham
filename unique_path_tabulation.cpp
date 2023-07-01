// https://leetcode.com/problems/unique-paths/

#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N][N];


int main(){
int ro, col;
cin>>ro>>col;

dp[0][0] = 1;

for(int i = 0; i < ro; i++){
    for(int j = 0; j < col; j++){
        if(i == 0 && j == 0){
            continue;
        }

        int ans = 0;
        if(ro > 0)ans += dp[i-1][j];
        if(col > 0)ans += dp[i][j-1];
        dp[i][j] = ans;
    }
}

cout<<dp[ro-1][col-1];

 return 0;
}
