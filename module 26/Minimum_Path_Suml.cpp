//#include<bits/stdc++.h>
//using namespace std;
//const int N = 105;
//int dp[N][N];
//int cost[3][3] = { { 1, 2, 3 }, { 4, 8, 2 }, { 1, 5, 3 } };
//
//int minimumPathSum(int n, int m){
//    // base case;
//    if(n == 0 && m == 0) return cost[n][m];
//
//    if(dp[n][m] != -1){
//        return dp[n][m];
//    }
//
//    int ans = 0;
//
//    if(n>0 && m> 0){
//        ans += min(minimumPathSum(n-1, m)+cost[n][m], minimumPathSum(n, m-1) + cost[n][m]);
//        dp[n][m] = ans;
//        return ans;
//    }
//
//
//
//}
//
//
//
//int main(){
//
//
//    for(int i = 0; i < 3; i++){
//        for(int j = 0; j < 3; j++){
//            dp[i][j] = -1;
//        }
//
//    }
//
//    cout<<minimumPathSum(2, 2);
//
// return 0;
//
//}


#include<bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N][N];
int cost[2][3] = {{1,2,3}, {4,5,6}};

int minimumPathSum(int n, int m){
    // base case;
    if(n == 0 && m == 0) return cost[n][m];

    if(dp[n][m] != -1){
        return dp[n][m];
    }

    int ans = INT_MAX; // initialize ans to the maximum possible value

    if(n > 0){
        ans = min(ans, minimumPathSum(n-1, m) + cost[n][m]);
    }
    if(m > 0){
        ans = min(ans, minimumPathSum(n, m-1) + cost[n][m]);
    }

    dp[n][m] = ans;
    return ans;
}



int main(){
    int row = sizeof(cost) / sizeof(cost[0]);
    int col = sizeof(cost[0]) / sizeof(cost[0][0]);



    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            dp[i][j] = -1;
        }
    }

    cout<<minimumPathSum(row-1, col-1);

    return 0;
}
