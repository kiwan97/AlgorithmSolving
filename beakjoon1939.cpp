#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int N,M,A,B,C;
int S,E;
int l,h,mid;
vector<pair<int,int> > adj[10005];
bool visited[10005];

bool bfs(int w){
	memset(visited,false,sizeof(visited));
	queue<int> q;
	q.push(S);
	visited[S] = true;
	int t;
	while(!q.empty()){
		t = q.front();
		q.pop();
		for(int i=0;i<adj[t].size();i++){
			if(visited[adj[t][i].first])
				continue;
			if(adj[t][i].second >= w){
				visited[adj[t][i].first] = true;
				if(adj[t][i].first == E)
					return true;
				q.push(adj[t][i].first);
			}
		}
	}
	return false;

}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	h = 1;
	for(int i=0;i<M;i++){
		cin >> A >> B >> C;
		adj[A].push_back({B,C});
		adj[B].push_back({A,C});
		h = max(h,C);
	}

	cin >> S >> E;

	l = 1;

	while(l<h){
		mid = (l+h)/2;

		if(bfs(mid)){
			l = mid+1;
		}else{
			h = mid;
		}
	}
	
	if(!bfs(l)){
		l--;
	}
	cout << l;
	return 0;
}