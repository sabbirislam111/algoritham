#include <iostream>
using namespace std;

// function to check if a is parent of b
bool isParent(int a, int b, int ancestor[]) {
    // traverse up the tree from b to check if a is an ancestor of b
    while (b != 0) {
        if (ancestor[b] == a) {
            return true;
        }
        b = ancestor[b];
    }
    return false;
}

int main() {
    // read the number of vertices in the tree
    int n;
    cin >> n;

    // read the ancestor of each vertex
    int ancestor[n+1];
    for (int i = 1; i <= n; i++) {
        cin >> ancestor[i];
    }

    // read the number of queries
    int m;
    cin >> m;

    // process each query
    for (int i = 0; i < m; i++) {
        // read the vertices a and b
        int a, b;
        cin >> a >> b;

        // check if a is parent of b
        if (isParent(a, b, ancestor)) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    }
    return 0;
}
