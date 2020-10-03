#include <iostream>
#include <vector>

using namespace std;

long long cost[505];
struct Data{
	int a;
	int b;
	int c;
};
vector<Data> adj;
int N,M;
int A,B,C;

void init(){
	for(int i=0;i<505;i++)
		cost[i] = 1e9;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();

	cin >> N >> M;
	Data data;
	for(int i=0;i<M;i++){
		cin >> data.a >> data.b >> data.c;
		adj.push_back(data);
	}
	cost[1] = 0;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			auto cur = adj[j];
			if(cost[cur.a]==1e9)
				continue;
			if(cost[cur.a]+cur.c < cost[cur.b]){
				cost[cur.b] = cost[cur.a]+cur.c;
			}
		}
	}
	bool flag = false;

	for(int j=0;j<M;j++){
		auto cur = adj[j];
		if(cost[cur.a]==1e9)
			continue;
		if(cost[cur.a]+cur.c < cost[cur.b]){
			flag = true;
			break;
		}
	}

	if(flag){
		cout << -1;
		return 0;
	}

	for(int i=2;i<=N;i++){
		if(cost[i]==1e9)
			cout << -1;
		else
			cout << cost[i];
		if(i<N)
			cout << '\n';
	}
	return 0;
}