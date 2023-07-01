#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1e5;

int num[N];
int dp[N][M];

bool subset_sum(int n, int target){
    //1. base case
    if(n == 0){
        if(target == 0) return 1;
        return 0;
    }
    //2. if value is already calculate return it
    if(dp[n][target] != -1){
        return dp[n][target];
    }

    //3. calculate result from smaller sub problem
    int ans1 = subset_sum(n-1, target);
    if(target < num[n]){
        dp[n][target] = ans1;
        return ans1;
    }

    int ans2 = subset_sum(n-1, target - num[n]);
    int ans = ans1 or ans2;
    dp[n][target] = ans;
    return ans;




}


int main(){
    int n, target;
    cin>>n >> target;

    for(int i = 1; i<= n; i++){
        cin>>num[i];
    }

    for(int i =0;i <= n; i++){
        for(int j= 0; j<=target; j++){
            dp[i][j] = -1;
        }
    }


    cout<<subset_sum(n, target)<<endl;
//
//       for(int i =0;i <= n; i++){
//        for(int j= 0; j<=target; j++){
//            cout<<dp[i][j];
//        }
//        cout<<endl;
//    }




 return 0;
}


/*
6 9
3 34 4 12 5 2
*/
