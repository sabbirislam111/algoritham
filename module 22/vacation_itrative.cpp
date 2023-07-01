// https://atcoder.jp/contests/dp/tasks/dp_c

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int dp[N][4];
int happines[N][4];



int main()
{
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            cin>>happines[i][j];
        }
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j<= 3; j++)
        {
            dp[i][j] = -1;
        }
    }

    for (int day = 1; day <= n; day++)
    {
        for (int current_task = 1; current_task <= 3; current_task++)
        {
            int max_profit = 0;
            for (int last_task = 1; last_task <= 3; last_task++)
            {
                if (last_task != current_task)
                {
                    max_profit = max(max_profit, dp[day-1][last_task] + happines[day][current_task]);
                }
            }
            dp[day][current_task] = max_profit;
        }
    }



    int ans1 = dp[n][1];
    int ans2 = dp[n][2];
    int ans3 = dp[n][3];

    cout<<max({ans1, ans2, ans3})<<endl;



    return 0;
}


