// https://atcoder.jp/contests/dp/tasks/dp_b

// recursive way

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
const int INF = 1e8;
int n, k;
int dp[N];
int h[N];


int ston2(int n){
    if(n == 1) return 0;

    // if answer is already calculate
    if(dp[n] != -1) return dp[n];


    // calculate ans form smaller sub problem
    int ans = INF;
    for(int i = 1; i<=k; i++){

        if(n-i <= 0){
            break;
        }

        int temp_ans = ston2(n-i) + abs(h[n] - h[n-i]);
        ans = min(ans, temp_ans);

    }
    dp[n] = ans;
    return ans;

}

int main(){

    cin>>n>>k;
    for(int i = 1; i <= n; i++){
        cin>>h[i];
    }

     for(int i = 1; i <= n; i++){
        dp[i] = -1;
    }



    cout<<ston2(n);





 return 0;
}
