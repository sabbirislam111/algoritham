#include <iostream>
using namespace std;

int count_ways(int n) {
    int dp[n+1][3];
    dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][2];
        dp[i][2] = dp[i-1][0] + dp[i-1][1];
    }
    return dp[n][0] + dp[n][1] + dp[n][2];
}

int main() {
    int n;

    cin >> n;
    cout <<count_ways(n) << endl;
    return 0;
}
