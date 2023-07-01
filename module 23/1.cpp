#include <iostream>
#include <cstring>
using namespace std;
const int N = 1e5;
int coinValues[N];
int dp[N];
int maxCoins(int n) {
    if (n <= 0) return 0;
    if (dp[n] != -1) return dp[n];

    int ans = max(maxCoins(n-1), coinValues[n] + maxCoins(n-2));
    dp[n] = ans;
    return ans;
}

int main() {
    int testCases;
    cin >> testCases;
    for (int i = 1; i <= testCases; i++) {
        int n;
        cin >> n;
        for (int j = 1; j <= n; j++) {
            cin >> coinValues[j];
        }
        memset(dp, -1, sizeof(dp));
        int result = maxCoins(n);
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
