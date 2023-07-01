#include <bits/stdc++.h>
using namespace std;

int t, n, k;
int bushes[1000];
int dp[1005];

int max_blueberries(int i, int j) {
    if (i >= n || j == 0) {
        return 0;
    }
    if (dp[j] != -1) {
        return dp[j];
    }
    int pick = 0, skip = 0;
    if (j >= bushes[i]) {
        pick = bushes[i] + max_blueberries(i+2, j-bushes[i]);
    }
    skip = max_blueberries(i+1, j);
    cout<<pick<<" "<<skip<<endl;
    dp[j] = max(pick, skip);
    return dp[j];
}

int main() {
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> bushes[j];
        }
        memset(dp, -1, sizeof dp);
        cout << "Scenario #" << i << ": " << max_blueberries(0, k) << endl;
    }
    return 0;
}


