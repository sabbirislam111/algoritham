#include<bits/stdc++.h>
using namespace std;
/*
1 -Define a function backtrack that takes a string s, an integer n, and a reference to an integer count.
2 -If the length of s is equal to n, increment count and return.
3 -Otherwise, for each character c in the set {1, 2}, check if adding c to s would result in two adjacent characters that are the same.
4 -If not, add c to s and recursively call backtrack with the updated string s.
5 -When the recursive calls return, the function will have counted all valid strings of length n.

*/
void backtrack(string s, int n, int& count) {
    if (s.length() == n) {
        count++;
        return;
    }
    for (char c : {'1', '2'}) {
        if (s.length() >= 2 && s[s.length()-1] == s[s.length()-2] && c == s[s.length()-1]) {
            continue;
        }
        backtrack(s + c, n, count);
    }
}




int count_numbers(int n) {
    int count = 0;
    string s;

    // lambda function
//    function<void(string)> backtrack = [&](string s) {
//        if (s.length() == n) {
//            count++;
//            return;
//        }
//        for (char c : {'1', '2'}) {
//            if (s.length() >= 2 && s[s.length()-1] == s[s.length()-2] && c == s[s.length()-1]) {
//                continue;
//            }
//            backtrack(s + c);
//        }
//    };

    backtrack(s, n, count);
    return count;
}

int main() {
    int n = 3;
    cout << count_numbers(n) << endl;  // output: 6
    return 0;
}
