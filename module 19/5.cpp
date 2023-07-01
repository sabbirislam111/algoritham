#include<bits/stdc++.h>
using namespace std;
int n;
pair<int, int>src, des;
const int N = 2002;
int maze[N][N], visited[N][N], levele[N][N], parent[N][N];
int dx[] ={0, 0, -1, 1};
int dy[] ={1, -1, 0, 0};

bool is_forbidden(pair<int, int> coord){
    int x = coord.first;
    int y = coord.second;

    if(maze[x][y] == 0){
        return true;
    }
    return false;

}


bool is_inside(pair<int,int>coord){
    int x = coord.first;
    int y = coord.second;

    if(x>= 0 && x < n && y >= 0 && y < n){
        return true;
    }
    return false;

}

void bfs(pair<int, int>src){
    queue<pair<int, int>>q;

    visited[src.first][src.second] = 1;
    levele[src.first][src.second] = 0;
    q.push(src);

    while(!q.empty()){
        pair<int, int>head = q.front();
        q.pop();
        int x = head.first;
        int y = head.second;

        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            pair<int, int>adjacent_node = {new_x, new_y};

            if(is_inside(adjacent_node) && !is_forbidden(adjacent_node) && visited[new_x][new_y] == 0){
                visited[new_x][new_y] = 1;
                levele[new_x][new_y] = levele[x][y] +1;
                parent[new_x][new_y] = {x, y};
                q.push(adjacent_node);
            }

        }

    }

}


int main(){

    cin>>n;

     for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            maze[i][j] = -1;
        }

    }

    for(int i = 0; i < n; i++){
        string input;
        cin>>input;
        for(int j = 0; j < n; j++){
            if(input[j] == 'O'){
                maze[i][j] = 0;
            }
            else if(input[j] == 'X'){
                src = {i, j};
            }
            else if(input[j] == '@'){
                des = {i, j};
            }
        }
    }

    bfs(src);

    for(int i = 0; i < n; i++){
        for(int j = 0; j <n; j++){
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }


 return 0;
}
