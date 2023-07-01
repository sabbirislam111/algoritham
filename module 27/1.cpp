// A naive recursive C++
// program to find minimum
// number of squares whose sum
// is equal to a given number
#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
// Returns count of minimum
// squares that sum to n
int getMinSquares(unsigned int n)
{
	// base cases
	// if n is perfect square then
	// Minimum squares required is 1
	// (144 = 12^2)

	if (sqrt(n) - floor(sqrt(n)) == 0)
		return 1;
	if (n <= 3)
		return n;

	// getMinSquares rest of the
	// table using recursive
	// formula
	// Maximum squares required
	// is n (1*1 + 1*1 + ..)
	if(dp[n] != -1){
        return dp[n];
	}

	int res = n;

	// Go through all smaller numbers
	// to recursively find minimum
	for (int x = 1; x <= n; x++)
	{
		int temp = x * x;
		if (temp > n)
			break;
		else
			res = min(res, 1 + getMinSquares(n - temp));
	}
	return dp[n] = res;
}

// Driver code
int main()
{
    memset(dp, -1, sizeof(dp));
	cout << getMinSquares(12);


	return 0;
}

