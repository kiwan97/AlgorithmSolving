#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int N,M,T;
vector<pair<int,int> > v;
bool visited[1005];
bool comp2(pair<int,int>& a,pair<int,int>& b){
	if(a.second == b.second)
		return a.first > b.first;
	return a.second < b.second;
}

bool addIt(int s,int e){
	for(int i=s;i<=e;i++){
		if(visited[i])
			continue;
		visited[i] = true;
		return true;
	}
	return false;
}

int main(){
	cin >> T;
	while(T--){
		cin >> N >> M;
		int a,b;
        v.clear();
        memset(visited,false,sizeof(visited));
		for(int i=0;i<M;i++){
			cin >> a >> b;
			v.push_back({a,b});
		}
		int ans = 0;
		sort(v.begin(),v.end(),comp2);
		for(int i=0;i<v.size();i++){
			if(addIt(v[i].first,v[i].second))
				ans++;
		}
		cout << ans << '\n';
		
	}
	return 0;
}