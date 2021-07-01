#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

bool adj[55][55];
bool visit[55];
int N;

int bfs(int v){
	queue<int> q;
	q.push(v);
	int ret = 0;

	for(int k=0;k<2;k++){
		int sz = q.size();
		for(int i=0;i<sz;i++){
			int t = q.front();
			q.pop();
			for(int j=0;j<N;j++){
				if(adj[t][j] && !visit[j]){
					visit[j] = true;
					q.push(j);
					ret++;
				}
			}
			
		}
	}

	while(!q.empty())
		q.pop();

	return ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(adj,false,sizeof(adj));
	string s;

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> s;
		for(int j=0;j<N;j++){
			if(s[j]=='Y')
				adj[i][j] = true;
		}
	}

	int maxi = 0;

	for(int i=0;i<N;i++){
		memset(visit,false,sizeof(visit));
		visit[i] = true;
		maxi = max(maxi,bfs(i));
	}
	cout << maxi << '\n';
	return 0;
}