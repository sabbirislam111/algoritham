
/*

5 8
########
#M..A..#
#.#.M#.#
#M#..#..
#.######

*/

#include<bits/stdc++.h>
using namespace std;

const int N = 2002;
int maze[N][N], visited[N][N], levele[N][N];
int n, m;
int dx[] ={0, 0, -1, 1};
int dy[] ={1, -1, 0, 0};

bool is_inside(pair<int,int>coord){
    int x = coord.first;
    int y = coord.second;

    if(x>= 0 && x < n && y >= 0 && y < m){
        return true;
    }
    return false;

}

bool is_forbidden(pair<int, int> coord){
    int x = coord.first;
    int y = coord.second;

    if(maze[x][y] == -1){
        return true;
    }
    return false;

}




pair<int, int> find_unvisited(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(visited[i][j] == 0 && maze[i][j] == 2){
                return {i, j};
            }
        }
    }
    return {-1, -1};

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
                q.push(adjacent_node);
            }

        }

    }

}


int main(){

    cin>>n>>m;
    pair<int, int>src, dst;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            levele[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++){
        string input;
        cin>>input;
        for(int j = 0; j < m; j++){
            if(input[j] == '#'){
                maze[i][j] = -1;
            }
           else if(input[j] == 'M'){
                maze[i][j] = -1;
            }
            else if(input[j] == 'A'){
                dst = {i, j};
            }

            else if(j == 0 || j == m-1){
                if(input[j] == '.'){
                    maze[i][j] = 2;
                    //dst = {i, j};
                }

            }
            else if(i == 0 || i == (n-1)){
                    if(input[j] == '.'){
                        maze[i][j] = 2;
                        //dst = {i, j};
                    }
            }
        }
    }

    //bfs(src);


    while(1){
        pair<int, int>unvisited_pos = find_unvisited();

        if(unvisited_pos == pair<int, int>(-1, -1)){
            break;
        }

        bfs(unvisited_pos);

    }

    if(levele[dst.first][dst.second] == -1){
        cout<<"No"<<endl;
    }
    else{
        cout<<"yes"<<endl;
        cout<<levele[dst.first][dst.second]<<endl;
    }


    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout<<maze[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;



 return 0;
}


// https://cses.fi/problemset/task//1192

