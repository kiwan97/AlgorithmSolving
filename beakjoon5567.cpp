#include <iostream>
#include <queue>
using namespace std;

bool adj[505][505];
bool visited[505];
int n,m;
int a,b;

int bfs(int v){

	queue<int> q;
	q.push(v);
	visited[v]=true;
	int sz;
	int ans=0;
	for(int j=0;j<2;j++){
		sz = q.size();
		while(sz--){
			int t = q.front();
			q.pop();
			for(int i=1;i<=n;i++){
				if(adj[t][i]&&!visited[i]){
					visited[i]=true;
					q.push(i);
					ans++;
				}
			}
		}
	}
	return ans;
	
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;
	for(int i=0;i<m;i++){
		cin >> a >> b;
		adj[a][b] = adj[b][a] = true;
	}

	cout << bfs(1);

	return 0;
}