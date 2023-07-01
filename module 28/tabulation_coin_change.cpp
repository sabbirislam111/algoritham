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
            for(int target = 0; target <= k; target++){
                dp[i][target] = 0;
            }
        }

        // base case
        dp[0][0] = 1;

        for(int i = 1; i <= n; i++){
            for(int target = 0; target <= k; target++){
                // calculate answer form smaller sub problem
                dp[i][target] = dp[i-1][target];

                for(int j = 1; j <= limit[i]; j++){
                    if(target < j *coin[i]){
                        break;
                    }
                   int ret = dp[i-1][target - j * coin[i]];
                   dp[i][target] = (dp[i][target] + ret) % MOD;
                }
            }
        }


        cout<<"Case"<<++q<<": "<<dp[n][k]<<endl;
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
