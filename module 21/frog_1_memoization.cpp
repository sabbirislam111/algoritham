// https://atcoder.jp/contests/dp/tasks/dp_a


#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int h[N];
int dp[N];

/*
    - state: stone(n) -> cost of reaching n-th stone from 1st stone
    - Recurrance: stone(n) -> min(

                                  stone(n-1) + abs(h[n] - h[n-1])
                                  stone(n-2) + abs(h[n] - h[n-2])
                                  )
    - base case: stone(1) = 0


*/

int stone(int n){
    // base case
    if(n == 1){
        return 0;
    }
    // check if answer already eaisest
    if(dp[n] != -1){
        return dp[n];
    }

    // calculate answer from subproblems


    int ans1 = (stone(n-1) + abs(h[n] - h[n-1]));

    // corner case for error heandeling
    if(n == 2){
        dp[n] = ans1;
        return ans1;
    }
    int ans2 = (stone(n-2) + abs(h[n]- h[n - 2]));

    int ans = min(ans1, ans2);
    dp[n] = ans;
    return ans;


}


int main(){

    int n;
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>h[i];
    }
    for(int i = 1; i <= n; i++){
        dp[i] = -1;
    }

    cout<<stone(n)<<endl;


 return 0;
}
