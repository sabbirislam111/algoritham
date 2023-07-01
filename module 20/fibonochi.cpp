#include<bits/stdc++.h>
using namespace std;
long long memory[101];


long long fibo(int n){
    if(n <=2) return 1;
    if(memory[n] != 0) return memory[n];

     memory[n] = fibo(n-1) + fibo(n-2);
    return memory[n];
}

int main(){

     cout<<fibo(50);



 return 0;
}
