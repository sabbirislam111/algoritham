#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int dp[N];


/*
    - dp[n] => calculate the nth  tribonacci number
    - dp[n] = dp[n-1] + dp[n-2] + dp[n - 3];
    - dp[1], dp[2], dp[3] = 1;




1*/

int main(){
    int n;
    cin>>n;
    dp[1] =1;
    dp[2] = 1;
    dp[3] = 1;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
    }
    cout<<dp[n]<<endl;









 return 0;
}
