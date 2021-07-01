#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

#define INF 1e9

int N,E,a,b,c;
int v1,v2;
int OneToV1, OneToV2, V1ToV2, NToV1, NToV2;
int cost[805];
vector<pair<int,int> > adj[805];//pair<cost,vertex>
priority_queue<pair<int,int> > pq; // pair<cost,vertex>

void dijkstra(int v){
	for(int i=0;i<=N;i++){
		cost[i]=INF;
	}
	cost[v]=0;
	pq.push({0,v});
	int sz;
	int cnt=0;
	int vv,nxt,nxt_cost;
	pair<int,int> t;

	while(!pq.empty()){
		t = pq.top();
		vv = t.second;
		pq.pop();
		sz = adj[vv].size();
		for(int i=0;i<sz;i++){
			nxt = adj[vv][i].second; nxt_cost=adj[vv][i].first;

			if(cost[nxt] > cost[vv]+nxt_cost){
				cost[nxt] = cost[vv]+nxt_cost;
				pq.push({-cost[nxt],nxt});
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> E;
	for(int i=0;i<E;i++){
		cin >> a >> b >> c;
		adj[a].push_back({c,b}); //pair<cost,vertex>
		adj[b].push_back({c,a}); //pair<cost,vertex>
	}
	cin >> v1 >> v2;

	dijkstra(1);

	OneToV1 = cost[v1];
	OneToV2 = cost[v2];

	dijkstra(v1);

	V1ToV2 = cost[v2];

	dijkstra(N);

	NToV1 = cost[v1];
	NToV2 = cost[v2];

	long long ans,ans2;

	ans = ans2 = 0;
	ans = OneToV1; 
	ans +=V1ToV2;
	ans +=NToV2;
	ans2 = OneToV2; 
	ans2 += V1ToV2;
	ans2 += NToV1;
	

	ans = min(ans,ans2);

	if(ans>=INF)
		cout << -1;
	else
		cout << ans;
	

	return 0;
}