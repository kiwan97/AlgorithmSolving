#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector< pair<int,int> > adj[505];
int TC,N,M,W,S,E,T;
int cost[505];

void init(){
	for(int i=0;i<505;i++){
		cost[i] = 1e9;
		adj[i].clear();
	}
}

bool bellmanFord(){
	cost[1] = 0;

	for(int i=0;i<N;i++){
		for(int j=1;j<=N;j++){
			int sz = adj[j].size();
			for(int k=0;k<sz;k++){
				if(cost[adj[j][k].first] > cost[j] + adj[j][k].second){
					cost[adj[j][k].first] = cost[j] + adj[j][k].second;
				}
			}
		}
	}

	for(int j=1;j<=N;j++){
		int sz = adj[j].size();
		for(int k=0;k<sz;k++){
			if(cost[adj[j][k].first] > cost[j] + adj[j][k].second){
				return false;
			}
		}
	}
	return true;
}
int main(){
	
	cin >> TC;
	while(TC--){
		init();
		cin >> N >> M >> W;
		for(int i=0;i<M;i++){
			cin >> S >> E >> T;
			for(int j=0;j<adj[S].size();j++){
				if(adj[])
			}
			adj[S].push_back({E,T});
			adj[E].push_back({S,T});
		}
		for(int i=0;i<W;i++){
			cin >> S >> E >> T;
			T*=-1;
			adj[S].push_back({E,T});
			adj[E].push_back({S,T});
		}

		if(bellmanFord())
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}