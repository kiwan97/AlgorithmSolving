#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M,a,b;
vector<int> adj[10005];
bool visit[10005];
vector<int> ans;
int maxi=0;
int tmp=0;
int dfs(int v){
	if(visit[v])
		return 0;
	visit[v]=true;
	int sum = 1;
	int sz = adj[v].size();
	for(int i=0;i<sz;i++)
		sum += dfs(adj[v][i]);
	return sum;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;

	for(int i=0;i<M;i++){
		cin >> a >> b;
		adj[b].push_back(a);
	}
	
	for(int i=1;i<=N;i++){
		memset(visit,false,sizeof(visit));
		tmp = dfs(i);

		if(tmp>maxi){
			ans.clear();
			ans.push_back(i);
			maxi=tmp;
		}else if(tmp==maxi){
			ans.push_back(i);
		}
	}

	sort(ans.begin(),ans.end());

	int sz = ans.size();
	for(int i=0;i<sz;i++)
		cout << ans[i] <<' ';
	return 0;
}