#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 210;
int n, T, kase;
int f[N][N];

int dfs(int i, int j) {
    if (f[i][j] != -1) return f[i][j];
    int ans = 0;
    if (i + 1 <= 2 * n - 1)
        ans = max(ans, dfs(i + 1, j));
    if (i + 1 <= 2 * n - 1 && j + 1 <= i + 1)
        ans = max(ans, dfs(i + 1, j + 1));
    return f[i][j] = ans + f[i][j];
}

int main() {
    cin >> T;
    while (T--) {
        memset(f, -1, sizeof f);
        cin >> n;
        for (int i = 1; i <= 2 * n - 1; i++)
            for (int j = 1; j <= i; j++)
                cin >> f[i][j];
        cout << "Case " << ++kase << ": " << dfs(1, 1) << endl;
    }
    return 0;
}

