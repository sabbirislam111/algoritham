// https://lightoj.com/problem/coin-change-i

#include<bits/stdc++.h>
using namespace std;
const int N = 60;
const int M = 1001;
const int MOD = 100000007;

int dp[N][M];

int coin[N], limit[N];

int fun(int n, int k){

    // base case
    if(n == 0){
        if(k == 0) return 1;
        return 0;
    }

    // if result is already calculate return it
    if(dp[n][k] != -1){
        return dp[n][k];
    }

    // calculate result from smaller sub problem
    int ans = fun(n - 1, k);

    for(int i = 1; i <= limit[n]; i++){
        if(k - i* coin[n] < 0){
            break;
        }
       int ret = fun(n-1, k - i*coin[n]);
       ans = (ans + ret) % MOD;
    }
    dp[n][k] = ans;
    return ans;



}


int main(){
    int q;
    cin>>q;

    while(--q){
        int n, k;
        cin>>n>>k;

        for(int i = 1; i <= n; i++){
            cin>>coin[i];
        }

         for(int i = 1; i <= n; i++){
            cin>>limit[i];
        }

        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= k; j++){
                dp[i][j] = -1;
            }
        }
        cout<<"Case"<<++q<<": "<<fun(n,k)<<endl;
    }





/*
2
3 5
1 2 5 3 2 1
4 20
1 2 3 4 8 4 2 1

*/


 return 0;
}
