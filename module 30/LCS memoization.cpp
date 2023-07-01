#include<bits/stdc++.h>
using namespace std;
const int N = 3003;
int n, m;
string s, t;
int dp[N][N];

int lcs(int i, int j){
    if(i == n || j == m){
       return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    if(s[i] == t[j]){
        int ans = 1 + lcs(i+1, j+1);
        dp[i][j] = ans;
        return ans;
    }

    int ans = max(lcs(i+1, j), lcs(i, j+1));
    dp[i][j] = ans;
    return ans;

}


int main(){

    cin>>s>>t;

    n = s.size();
    m = t.size();

    for(int i = 0; i<= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }


    cout<<lcs(0, 0);



/*
axyb
abyxb
*/




 return 0;
}
