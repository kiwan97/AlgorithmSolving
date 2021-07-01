#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int V,a,b,c;
bool visit[100005];
int ans = 0;

vector<pair<int,int> > adj[100005];

int dfs(int n){
	int child,child_len;
	int sz = adj[n].size();
	visit[n]=true;
	if(sz==1 && n!=1)
		return 0;
	vector<int> tmp_v;
	tmp_v.clear();
	

	for(int i=0;i<sz;i++){
		child = adj[n][i].first;
		child_len = adj[n][i].second;
		if(visit[child])
			continue;
		tmp_v.push_back(dfs(child)+child_len);
	}

	sort(tmp_v.begin(),tmp_v.end());
	int sz2 = tmp_v.size();

	if(sz2==1){
		ans = max(ans,tmp_v[0]);
		return tmp_v[0];
	}


	ans = max(ans,tmp_v[sz2-1]+tmp_v[sz2-2]);
	return tmp_v[sz2-1];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> V;
	for(int i=0;i<V;i++){
		cin >> a;
		while(true){
			cin >> b;
			if(b==-1)
				break;
			cin >> c;
			adj[a].push_back({b,c});
		}
	}

	dfs(1);

	cout << ans;

	return 0;
}