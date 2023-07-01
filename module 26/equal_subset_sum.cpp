// https://leetcode.com/problems/partition-equal-subset-sum/

#include<bits/stdc++.h>
using namespace std;
bool is_subset_sum(int arr[], int n, int sum){
    //base case
    if(sum == 0) return 1;
    if(n == 0 && sum != 0) return 0;

    if(arr[n-1] > sum){
        return is_subset_sum(arr, n-1, sum);
    }

    return is_subset_sum(arr, n-1, sum) || is_subset_sum(arr, n-1, sum - arr[n-1]);

}

bool find_partition(int arr[], int n){

    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    if(sum % 2 != 0) return 0;

    return is_subset_sum(arr, n, sum/2);

}

int main(){
    int num[] = {1,5,11,5};
    int n = sizeof(num)/sizeof(num[0]);

    if(find_partition(num, n) == 1){
        cout<<"yes";
    }
    else{
        cout<<"NO";
    }


 return 0;
}
