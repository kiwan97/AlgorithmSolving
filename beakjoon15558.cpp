#include <iostream>
#include <queue>
using namespace std;

string line[2];
bool visited[2][100005];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N,K;
	cin >> N >> K;
	cin >> line[0] >> line[1];

	visited[0][0] = true;

	queue<pair<int,int> > q;
	q.push({0,0});

	int del = 0;
	int ans = 0;
	while(!q.empty()){
		int sz = q.size();
		while(sz--){
			auto t = q.front();
			q.pop();

			
			if(t.second+1 >= N || t.second+K >= N){
				ans=1;
				break;
			}

			if(t.second+1 > del && line[t.first][t.second+1] == '1' && !visited[t.first][t.second+1]){
				visited[t.first][t.second+1] = true;
				q.push({t.first,t.second+1});
			}
			if(t.second-1 > del && line[t.first][t.second-1] == '1' && !visited[t.first][t.second-1]){
				visited[t.first][t.second-1] = true;
				q.push({t.first,t.second-1});
			}
			if(t.second+K > del && line[(t.first+1)%2][t.second+K] == '1' && !visited[(t.first+1)%2][t.second+K]){
				visited[(t.first+1)%2][t.second+K] = true;
				q.push({(t.first+1)%2,t.second+K});
			}

		}
		if(ans==1)
			break;
		del++;
	}
	cout << ans;

	return 0;
}