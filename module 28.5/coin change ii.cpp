#include<bits/stdc++.h>
using namespace std;

int dfs(int i, int t, vector<int> &coins, vector<vector<int>> &dp) {
    if(!t) return 1;
    if(!i) return t % coins[i] == 0;
    if(dp[i][t] != -1) return dp[i][t];

    int notPick = dfs(i - 1, t, coins, dp);
    int pick = coins[i] <= t ? dfs(i, t - coins[i], coins, dp) : 0;

    return dp[i][t] = pick + notPick;
}

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

    return dfs(n - 1, amount, coins, dp);
}

int main() {
    int amount = 3;
    vector<int> coins = {2};

    int ways = change(amount, coins);
    cout << "Ways to make change for " << amount << ": " << ways << endl;
    return 0;
}

