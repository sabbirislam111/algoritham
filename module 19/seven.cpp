//#include<bits/stdc++.h>
//using namespace std;
//
//
//int n;
//vector<int> ancestors;
//int m;
//
//
//bool is_parent(int a, int b) {
//    while (b != 0) {
//        if (ancestors[b-1] == a) {
//            return true;
//        }
//        b = ancestors[b-1];
//    }
//    return false;
//}
//
//int main() {
//    cin >> n;
//    ancestors.resize(n);
//    for (int i = 0; i < n; i++) {
//        cin >> ancestors[i];
//    }
//    cin >> m;
//
//
//    for (int i = 0; i < m; i++) {
//        int a, b;
//        cin >> a >> b;
//        if (is_parent(a, b)) {
//            cout << 1 << endl;
//        } else {
//            cout << 0 << endl;
//        }
//    }
//
//    return 0;
//}

////////////////// 2222222222222222222222222

#include <iostream>
using namespace std;

int n, m, ancestors[100005], a, b;

int is_parent(int a, int b) {
    while (b != 0) {
        if (ancestors[b-1] == a) {
            return 1;
        }
        b = ancestors[b-1];
    }
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ancestors[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << is_parent(a, b) << endl;
    }
    return 0;
}

