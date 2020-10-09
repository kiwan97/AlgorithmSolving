#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> ii;
vector<vector<ii> > t;

bool visited[250001];
int ans[250005];
vector<ii> ttt;
ii far(int n,int cc){ // furthermost node from node n
	visited[n] = true;

	ii ret(n, 0); // (node,cost);
	for(int i=0; i<t[n].size(); ++i){
		int next = t[n][i].first;
		int cost = t[n][i].second;
		if(visited[next] == true)
			continue;
		ii child = far(next,cc+1);
		
		if(ret.second < child.second + cost){
			ret = ii(child.first, child.second + cost);
		}
	}
	ttt.push_back({n,cc});
	return ret;
}
int lll;
ii far2(int n,int cc,int target){ // furthermost node from node n
	visited[n] = true;

	ii ret(n, 0); // (node,cost);
	for(int i=0; i<t[n].size(); ++i){
		int next = t[n][i].first;
		int cost = t[n][i].second;
		if(visited[next] == true)
			continue;
		ii child = far2(next,cc+1,target);
		
		if(ret.second < child.second + cost){
			ret = ii(child.first, child.second + cost);
		}
	}
	ttt.push_back({n,cc});
	if(n==target){
		lll = cc;
	}
	return ret;
}
bool comp(ii& a,ii& b){
	return a.second > b.second;
}
vector<int> kkk;
int diameter_tree(int n){
	fill(visited, visited+n+1, false);
	ii u = far(1,0); // 1:root
	fill(visited, visited+n+1, false);
	memset(ans,0,sizeof(ans));
	ttt.clear();
	ii v = far(u.first,0);
	
	sort(ttt.begin(),ttt.end(),comp);
	kkk.push_back(ttt[0].second);
	kkk.push_back(ttt[1].second);

	int ll = ttt[0].first;
	int uu = ttt[1].first;

	fill(visited, visited+n+1, false);
	memset(ans,0,sizeof(ans));
	ttt.clear();
	v = far2(ll,0,uu);
	kkk.push_back(lll);
	return v.second;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
	t.resize(n+1);
	for(int i=0; i<n-1; ++i){
		int p, c, cost;
		p=edges[i][0];
		c=edges[i][1];
		cost=1;
		t[p].push_back(ii(c, cost));
		t[c].push_back(ii(p, cost));
	}
	int ss = diameter_tree(n);
	vector<int> realAns;
	
	sort(ans+1,ans+n+1);
	sort(ttt.begin(),ttt.end());
	// for(int i=0;i<ttt.size();i++){
	// 	cout << "ttt : "<<ttt[i] << '\n';
	// }
	sort(kkk.begin(),kkk.end());
	return kkk[1];
	// if(ttt[ttt.size()-1]==ttt[ttt.size()-2])
	// 	return ttt[ttt.size()-1];
	// else
	// 	return ttt[ttt.size()-2];
	// return ttt[ttt.size()-2];
}