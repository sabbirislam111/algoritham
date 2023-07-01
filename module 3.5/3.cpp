#include <bits/stdc++.h>
using namespace std;

int main(){

    int a = 0, i = 5;
    vector<int> vec;
    while (i > 0) {
        a += i;
        i /= 2;
        vec.push_back(a);
    }

    for(int i = 0; i < vec.size(); i++){
        cout<<vec[i]<<" ";
    }




 return 0;
}

//
//O(1): Constant complexity.
//O(logn): Logarithmic complexity.
//O(n): Linear complexity.
//O(nlogn): Loglinear complexity.
//O(n^x): Polynomial complexity.
//O(X^n): Exponential time.
//O(n!): Factorial complexity.
