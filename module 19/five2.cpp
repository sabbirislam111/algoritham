#include<bits/stdc++.h>
using namespace std;
const int N=45;
int n;
char a[N][N];
bool vis[N][N];
int dist[N][N];
char grid[45][45];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
typedef pair<int,int> PII;

bool check(int x,int y){
    if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]!='O'&&vis[x][y]==false) return true;
    return false;
}
//
//void bfs(int x,int y,int x2,int y2){
//    queue<PII> q;
//    q.push({x,y});
//    vis[x][y]=true;
//    while(!q.empty()){
//        PII now=q.front();
//        q.pop();
//        if(now.first==x2&&now.second==y2){
//            cout<<"Y\n";
//            for(int i=0;i<n;i++){
//                for(int j=0;j<n;j++){
//                    if(vis[i][j]) cout<<"+";
//                    else cout<<a[i][j];
//                }
//                cout<<endl;
//            }
//            return;
//        }
//        for(int i=0;i<4;i++){
//            int xx=now.first+dx[i];
//            int yy=now.second+dy[i];
//            if(check(xx,yy)){
//                vis[xx][yy]=true;
//                q.push({xx,yy});
//            }
//        }
//    }
//    cout<<"N\n";
//}


struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

bool bfs(Point &start, Point &end) {
    queue<Point> q;
    q.push(start);
    dist[start.x][start.y] = 0;

    Point *parent[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            *parent[i][j] = Point(-1, -1);
        }
    }

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        if (curr.x == end.x && curr.y == end.y) {
            // trace back the path using parent array
            Point curr_point = curr;
            while (curr_point.x != start.x || curr_point.y != start.y) {
                grid[curr_point.x][curr_point.y] = '+';
                curr_point = *parent[curr_point.x][curr_point.y];
            }
            return true;
        }

        for (int i = 0; i < 4; i++) {
            int nx = curr.x + dx[i], ny = curr.y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == '.' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[curr.x][curr.y] + 1;
                *parent[nx][ny] = curr;
                q.push({nx, ny});
            }
        }
    }
    return false;
}

int main(){
    cin>>n;
    Point *start, *end;
    int x,y,x2,y2;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if(a[i][j]=='@') *start = {i, j};
            if(a[i][j]=='X') *end = {i, j};
        }
    }
    bfs(*start, *end);
    return 0;
}

