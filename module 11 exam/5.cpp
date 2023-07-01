#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;

int n, m;
int sv, ev;
vector<int> g[N];
int vis[N];
int parent[N];


void bfs(int src)
{
    queue<int>q;
	vis[src] = 1;
	parent[src] = -1;
	q.push(src);

	while(!q.empty()){
        int head = q.front();
        q.pop();
        //cout<<head<<" ";

        for(int adj_node: g[head]){

            if(parent[adj_node] == head) continue;

            if(vis[adj_node] == 1){
                sv = adj_node;
                ev = head;
                break;


            }
            if(vis[adj_node] == 0 && parent[adj_node] != head){
                parent[adj_node] = head;
                vis[adj_node] = 1;
                q.push(adj_node);
            }
        }

	}
}


//bool visit_all()
//{
//	for(int i = 1; i <= n; ++i)
//	{
//		if(!vis[i]){
//            bool call = dfs(i,-1);
//            if(call) return true;
//		}
//
//	}
//	return false;
//}

int main()
{

	cin >> n >> m;

	for(int i =0 ; i < m; ++i)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	bfs(1);
//	if(!is_cycle)
//	{
//		cout << "IMPOSSIBLE" << endl;
//		return 0;
//	}

//	int tv = ev;
//	vector<int> ans;
//	ans.push_back(ev);
//	while(tv != sv)
//	{
//		ans.push_back(parent[tv]);
//		tv = parent[tv];
//	}
//	ans.push_back(ev);
//	cout << ans.size() << endl;
//	for(auto c: ans)
//	{
//		cout << c << " ";
//	}

    for(int i = 1; i <= n; i++){

            cout<<parent[i]<<" ";


    }

 return 0;
}

