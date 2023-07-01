#include<bits/stdc++.h>
using namespace std;
// memoization

const int N = 1e5 + 5;
int dp[N];

/*
    - tribo(n) => calculate the nth tribonacci number
    - tribo(n) = tribo(n-1) + tribo(n-2) + tribo(n-3)
    - tribo(1), tribo(2), tribo(3) = 1;


*/

int tribo(int n){
    if(n <= 3) return 1;

    if(dp[n] != -1){
        return dp[n];
    }
    dp[n] = tribo(n -1) + tribo(n - 2) + tribo(n- 3);
    return dp[n];


}


int main(){


    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        dp[i] = -1;
    }

    cout<<tribo(n)<<endl;




 return 0;
}
