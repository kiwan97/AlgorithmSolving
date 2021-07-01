#include <iostream>
#include <vector>
#include <utility>
#include <queue>
using namespace std;

#define INF 1e9

int N,E,a,b,c,v1,v2;
int cost[805][805];

void init_costMap(){
	for(int i=0;i<805;i++){
		for(int j=0;j<805;j++)
			cost[i][j]=INF;
	}
	for(int i=0;i<805;i++)
		cost[i][i]=0;
}

void floyd(){
	for(int m=1;m<=N;m++){
		for(int s=1;s<=N;s++){
			for(int e=1;e<=N;e++){
				if(cost[s][e] > cost[s][m] + cost[m][e])
					cost[s][e] = cost[s][m]+cost[m][e];
			}
		}
	}
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init_costMap();
	cin >> N >> E;
	for(int i=0;i<E;i++){
		cin >> a >> b >> c;
		if(cost[a][b]>c)
			cost[a][b]=cost[b][a]=c;
	}

	cin >> v1 >> v2;
	floyd();

	long long ans = 0;
	long long ans2 = 0;


	ans = cost[1][v1];
	ans += cost[v1][v2];
	ans+=cost[v2][N];

	ans2+=cost[1][v2];
	ans2+=cost[v2][v1];
	ans2+=cost[v1][N];
	
	ans = min(ans,ans2);

	if(ans>=INF)
		cout << -1;
	else
		cout << ans;

	return 0;
}