#include <iostream>
#include <queue>
using namespace std;
#define INF 1e9
int n,m,a,b,x,y;
bool adj[105][105];
int cost[105];

int bfs(){
	queue<int> q;
	q.push(a);
	cost[a]=0;
	int cnt = 0;
	while(!q.empty()){
		int sz = q.size();
		cnt++;
		while(sz--){
			int t = q.front();
			q.pop();
			for(int i=0;i<105;i++){
				if(adj[t][i] && cost[i]==INF){
					cost[i] = cost[t]+1;
					q.push(i);
					if(i==b){
						return cnt;
					}
				}
			}
		}
	}
	return -1;

}
void init(){
	for(int i=0;i<105;i++){
		cost[i]=INF;
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	cin >> n;
	cin >> a >> b;
	cin >> m;
	for(int i=0;i<m;i++){
		cin >> x >> y;
		adj[x][y] = adj[y][x] = true;
	}

	cout << bfs();


	return 0;
}