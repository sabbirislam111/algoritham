
#include <bits/stdc++.h>
using namespace std;

int main(){

  int a = 0;
    # space complexity O(1)
    # time complexity O(n)
    for (int i = 0; i < 3; i++) {
        for (int j = 5; j > i; j--) {
            a = a + i + j;
            cout<<a<<" ";
        }
    }




 return 0;
}
