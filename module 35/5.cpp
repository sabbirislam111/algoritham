#include<bits/stdc++.h>
using namespace std;

// Recursive function to compute the maximum amount of corns the mouse can take to reach cell (i, j)
int max_corns(vector<vector<int>> corns, int i, int j) {
    // Base case: the lower left cell
    if (i == 0 && j == 0) {
        return corns[0][0];
    }
    // Base case: cells on the left edge of the floor
    else if (i == 0) {
        return max_corns(corns, i, j-1) + corns[i][j];
    }
    // Base case: cells on the bottom edge of the floor
    else if (j == 0) {
        return max_corns(corns, i-1, j) + corns[i][j];
    }
    // Recursive case: other cells
    else {
        int max_corns_left = max_corns(corns, i, j-1);
        int max_corns_up = max_corns(corns, i-1, j);
        return max(max_corns_left, max_corns_up) + corns[i][j];
    }
}

int main() {
    // Read in the dimensions of the floor
    int m, n;
    cin >> m >> n;

    // Read in the number of corns on each tile
    vector<vector<int>> corns(m, vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> corns[i][j];
        }
    }

    // Compute the maximum amount of corns the mouse can take to reach the exit using recursion
    int max_corns_exit = max_corns(corns, m-1, n-1);

    // Print out the maximum amount of corns the mouse can take to reach the exit
    cout << max_corns_exit+1 << endl;

    return 0;
}

/*
2 3
2 6 4
1 5 1

*/



#include <iostream>
#include <vector>

using namespace std;

int max_corns_helper(vector<vector<int>>& corns, vector<vector<int>>& memo, int i, int j) {
    if (i < 0 || j < 0) {  // Base case: out of bounds
        return 0;
    }
    if (memo[i][j] >= 0) {  // Memoization
        return memo[i][j];
    }
    int max_up = max_corns_helper(corns, memo, i-1, j);  // Compute the maximum number of corns the mouse can take by going up
    int max_left = max_corns_helper(corns, memo, i, j-1);  // Compute the maximum number of corns the mouse can take by going left
    int max_corn = corns[i][j] + max(max_up, max_left);  // Compute the maximum number of corns the mouse can take by going up or left
    memo[i][j] = max_corn;  // Memoize the result
    return max_corn;
}

int max_corns(vector<vector<int>>& corns) {
    int m = corns.size();
    int n = corns[0].size();
    vector<vector<int>> memo(m, vector<int>(n, -1));  // Initialize memoization table with -1

    return max_corns_helper(corns, memo, m-1, n-1);  // Start from the lower right cell and return the maximum number of corns the mouse can take to reach the exit
}

int main() {
    vector<vector<int>> corns = {{3, 2, 4},
                                 {1, 5, 1}};
    cout << max_corns(corns) << endl;  // Output: 12
    return 0;
}
