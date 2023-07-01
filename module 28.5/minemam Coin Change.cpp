//#include <bits/stdc++.h>
//using namespace std;
//
//// size is length of coins[] array
//int minimumCoins(int coins[], int size, int V)
//{
//	// table[i] will store the result(minimum number of coins)
//	int table[V + 1];
//
//	//Just an edge case if the table element is 0
//	table[0] = 0;
//
//	// Initializing all table elements as infinite using INT_MAX
//	for (int i = 1; i <= V; i++)
//		table[i] = INT_MAX;
//
//	// Computing minimum values of coins for all array elements
//	for (int i = 1; i <= V; i++) {
//		for (int j = 0; j < size; j++)
//			if (coins[j] <= i) {
//				int sub_res = table[i - coins[j]];
//				if (sub_res != INT_MAX && sub_res + 1 < table[i])
//					table[i] = sub_res + 1;
//			}
//	}
//
//	if (table[V] == INT_MAX)
//		return -1;
//	return table[V];
//}
//
//// Driver program to test above function
//int main()
//{
//	int coins[] = {9,6,5,1 };
//	int size= sizeof(coins) / sizeof(coins[0]);
//	int V = 11;
//	cout << "Minimum coins required is "
//		<< minimumCoins(coins, size, V);
//	return 0;
//}





#include<bits/stdc++.h>
using namespace std;

// size is the length of coins array
int minimumCoins(int coins[], int size, int V)
{
// base case that is, if value is equal to 0, then
if (V == 0)
   return 0;
// Initialize result
int res = INT_MAX;
// Try every coin that has smaller value than V
for (int i=0; i<size; i++)
{
	if (coins[i] <= V)
	{
		int sub_res = minimumCoins(coins, size, V-coins[i]);
		if (sub_res != INT_MAX && sub_res + 1 < res)
			res = sub_res + 1;
	}
}
if(res == INT_MAX){
    return -1;
}
return res;
}

int main()
{
	int coins[] = {1,2,5};
	int size = sizeof(coins)/sizeof(coins[0]);
	int V = 11;
	cout << "Minimum coins required is "
		<< minimumCoins(coins, size, V);
	return 0;
}
