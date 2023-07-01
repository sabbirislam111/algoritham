#include<bits/stdc++.h>
using namespace std;
const int N = 101;


/*
    - fib(n) => calculate the nth Fibonacci number
    - fib(n) = fib(n-1) + fib(n-2)
    - fib(1) = 1, fib(2) = 1

*/

long long dp[N]; // DP array

long long fib(int n){
 // base case
 if(n <= 2) return 1;

 // check if current state is solved
 if(dp[n] != -1){ // current state is already solved
    return dp[n];
 }

 // calculate from smaller sub-priblems
 dp[n] = fib(n-1) + fib(n-2);
 return dp[n];



}

int main(){

    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp)); // mark all states as unvisited

    cout<<fib(n)<<endl;

 return 0;
}
