#include <bits/stdc++.h>
using namespace std;

const int N=1010;
int n,m;
double f[N];
int p[N];
int dp[N][N];

int knapsack(int i,int j)
{
    if(dp[i][j]!=-1) return dp[i][j];
    if(i==0 || j==0) return 0;
    int res=0;
    if(j<f[i-1]*100)
        res=knapsack(i-1,j);
    else
        res=max(knapsack(i-1,j),knapsack(i-1,j-(int)(f[i-1]*100))+p[i-1]);
    dp[i][j]=res;
    return res;
}

int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>f[i]>>p[i];
    memset(dp,-1,sizeof dp);
    m=m*2;
    cout<<knapsack(n,m)<<endl;
    return 0;
}





/*
Input:
(0.2, $5)
(0.3, $10)
(0.4, $15)
(0.1, $7)
(0.5, $25)



Answer:
Ad 3: (0.4, $15)
Ad 4: (0.1, $7)
Ad 5: (0.5, $25)
Total profit: $47


input:
5 50
0.2 0.3 0.4 0.1 0.5
5 10 15 7 25

output:  47



5 7
0.2 5
0.3 10
0.4 15
0.1 7
0.5 25

*/
