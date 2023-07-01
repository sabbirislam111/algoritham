//#include<bits/stdc++.h>
//using namespace std;
//
//int n, a[100005], sum[100005], dp[100005], MX= 100003;
//
//
//int main() {
//    memset(sum, 0, sizeof(sum));
//    cin>>n;
//
//    for(int i=0;i<n;i++){
//        cin>>a[i];
//        if(a[i]>MX) MX= a[i];
//        sum[a[i]]+= a[i];
//        cout<<sum[a[i]]<<endl;
//    }
//
//    dp[0]= 0; dp[1]= sum[1];
//
//    for(int i=2;i<=MX;i++)
//        dp[i]= max(dp[i-1], sum[i]+dp[i-2]);
//
//    cout<<dp[MX]<<endl;
//    return 0;
//}



//#include <bits/stdc++.h>
//typedef long long int ll;
//using namespace std;
//
//ll dp[1000005] = {0};
//
//ll bordom(int i){
//    if(i == 0) return 0;
//    if(i == 1) return dp[1];
//    return max(bordom(i-1), bordom(i-2) + i*dp[i]);
//}
//
//int main() {
//    int n, b, mx = 0;
//    cin>>n;
//    for(int i = 0; i < n; i++){
//        cin>>b;
//        dp[b]++;
//        mx = max(mx, b);
//    }
//    cout<<bordom(mx)<<endl;
//
//    return 0;
//}

#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

ll dp[1000005] = {0};
ll frq[1000005] = {0};

ll bordom(int i){
    if(dp[i] != 0) return dp[i];
    if(i == 0) return 0;
    if(i == 1) return frq[1];
    dp[i] = max(bordom(i-1), bordom(i-2) + i*frq[i]);
    return dp[i];
}

int main() {
    int n, b, mx = 0;
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>b;
        frq[b]++;
        mx = max(mx, b);
    }
    cout<<bordom(mx)<<endl;

    return 0;
}


