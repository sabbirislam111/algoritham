#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int M = 1e5;

int num[N];
int dp[N][M];


int main(){
    int n, m;
    cin>>n >> m;

    for(int i = 1; i<= n; i++){
        cin>>num[i];
    }

  // base case
  dp[0][0] = 1;
  for(int i = 1; i <= n; i++){
    dp[0][i] = 0;
  }

  // loop over the states
  for(int i = 1; i <= n; i++){
    for(int target = 1; target <= m; target++){
        // 2.1 calculate answer from smaller sub problem
        int ans1 = dp[i-1][target];
        if(target < num[i]){
            dp[i][target] = ans1;
        }
        else{
            int ans2 = dp[i - 1][target - num[i]];
            dp[i][target] = ans1 or ans2;
        }
    }
  }

  cout<< dp[n][m]<<endl;

       for(int i =0;i <= n; i++){
        for(int j= 0; j<=m; j++){
            cout<<dp[i][j];
        }
        cout<<endl;
    }



 return 0;
}

