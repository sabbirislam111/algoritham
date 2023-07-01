#include<bits/stdc++.h>
using namespace std;

int gen_rob(vector<int>& arr,int st,int end) {
    int p1=0,p2=0;
    int p3=0;
    for(int i=st;i<end;i++){
        p3=max(arr[i]+p2,p1);
        p2=p1;
        p1=p3;
    }
    return p3;
}

int rob(vector<int>& nums) {
    int n=nums.size();
    if(n==1)return nums[0];
    return max(gen_rob(nums,0,n-1),gen_rob(nums,1,n));
}

int main(){

    vector<int>nums = {1,2,3};
    cout<<rob(nums);


 return 0;
}
