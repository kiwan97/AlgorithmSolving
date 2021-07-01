#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
int N,M,a,b;

bool visit[10005];
int cnt[10005];
vector<int> adj[10005];
int dfs(int v){
	if(visit[v])
		return cnt[v]+1;
	visit[v] = true;
	int sum = 0;
	int sz = adj[v].size();
	for(int i=0;i<sz;i++)
		if(!visit[adj[v][i]]){
			sum += dfs(adj[v][i])+1;
		}

	return cnt[v]=sum;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(visit,false,sizeof(visit));
	memset(cnt,0,sizeof(cnt));

	cin >> N >> M;

	for(int i=0;i<M;i++){
		cin >> a >> b;
		adj[b-1].push_back(a-1);
	}

	for(int i=0;i<N;i++)
		dfs(i);

	vector<pair<int,int> > ans;
	vector<int> realAns;
	for(int i=0;i<N;i++){
		ans.push_back({cnt[i], i});
	}

	sort(ans.begin(),ans.end());
	for(int i=0;i<N;i++){
		cout << ans[i].first << ", " << ans[i].second << '\n';
		if(ans[N-1].first == ans[i].first){
			cout << ans[i].first << ", " << ans[i].second << '\n';
			realAns.push_back(ans[i].first);
		}
	}
	sort(realAns.begin(),realAns.end());

	int sz = realAns.size();
	for(int i=0;i<sz;i++){
		cout << realAns[i];
		if(i<sz-1)
			cout <<' ';
	}
	return 0;
}