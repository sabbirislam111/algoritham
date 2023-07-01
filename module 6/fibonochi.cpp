#include<bits/stdc++.h>
using namespace std;
int sum = 0;

int fibo(int n){

    // base case
    if(n == 0) return 0;
    if(n == 1) return 1;

   // Generalize  formula

   int a = fibo(n-1);
   int b = fibo(n -1);
    return a + b;

}



int main(){

    int n;
    cin>>n;
    cout<<fibo(n)<<endl;

//
//   int t1 = 0, t2 = 1, nextTerm = 0, n;
//
//    cout << "Enter a positive number: ";
//    cin >> n;
//
//    // displays the first two terms which is always 0 and 1
//    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";
//
//    nextTerm = t1 + t2;
//
//    while(nextTerm <= n) {
//        cout << nextTerm << ", ";
//        t1 = t2;
//        t2 = nextTerm;
//        nextTerm = t1 + t2;
//    }
    return 0;




}




