//#include <bits/stdc++.h>
//using namespace std;
//class Solution {
//   public:
//   int tallestBillboard(vector<int>& rods){
//      int sum = 0;
//      int n = rods.size();
//      int N = 2 * 5000;
//      vector<vector<int> > dp(n + 1, vector<int>(N + 1, -1));
//      dp[0][5000] = 0;
//      for (int i = 0; i < n; i++) {
//         for (int j = 0; j <= N; j++) {
//            int x = rods[i];
//            if (j - x >= 0 && dp[i][j - x] != -1) {
//               dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - x] +
//               x);
//            }
//            if (j + x <= N && dp[i][j + x] != -1) {
//               dp[i + 1][j] = max(dp[i + 1][j], dp[i][j + x]);
//            }
//            if (dp[i][j] != -1) {
//               dp[i + 1][j] = max(dp[i][j], dp[i + 1][j]);
//            }
//         }
//      }
//      return dp[n][5000];
//   }
//};
//main(){
//   Solution ob;
//   vector<int> v = {1,2,3,4,5,6};
//   cout << (ob.tallestBillboard(v));
//}



#include <bits/stdc++.h>
using namespace std;

   int tallestBillboard(vector<int>& rods, int i, int j) {
      int n = rods.size();
      if (i == n) return j == 5000 ? 0 : -1e9;
      int x = rods[i];
      int a = tallestBillboard(rods, i + 1, j - x);
      int b = tallestBillboard(rods, i + 1, j + x);
      int c = tallestBillboard(rods, i + 1, j);
      return max({a + x, b, c});
   }
   int tallestBillboard(vector<int>& rods) {
      return tallestBillboard(rods, 0, 5000);
   }


int main() {

   vector<int> v = {1,2,3};
   cout << tallestBillboard(v) << endl;
   return 0;
}


