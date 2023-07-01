#include<bits/stdc++.h>
using namespace std;

  bool is_palindrome(string str){
        if(str == "" || str.size() == 1){
            return true;
        }
        int n = str.size();
        string small_str = str.substr(1, n-2);
        return is_palindrome(small_str) && (str[0] == str.back());

    }

int main(){



    bool ans = is_palindrome("sabbir");

    if(ans == true){
        cout<<"palindrome";
    }
    else{
        cout<<"not palindrome";
    }
//
//   string  str = "sabbir";
//    cout<<str.substr(1, str.size()-2);

 return 0;
}


