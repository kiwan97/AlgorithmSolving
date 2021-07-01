#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N;
int Map[105][105];
int num=1;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int tx,ty;
bool visited[105][105];
bool visited_island[105];
int ans=10005;
queue<pair<int,int> > q;
queue<pair<int,int> > q2;

void nameTheIsland(int x,int y){
	
	while(!q.empty())
		q.pop();

	q.push({x,y});
	Map[x][y]=++num;

	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0;i<4;i++){
			tx = x+dx[i];
			ty = y+dy[i];
			if(tx<0 || ty<0 || tx>=N || ty>=N || Map[tx][ty]!=1)
				continue;
			Map[tx][ty] = num;
			q.push({tx,ty});
		}
	}

}

void bfs(int x,int y){
	int island_n = Map[x][y];
	int cnt=0;
	memset(visited,false,sizeof(visited));
	while(!q.empty())
		q.pop();
	while(!q2.empty())
		q2.pop();

	q.push({x,y});
	visited[x][y]=true;

	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();

		for(int i=0;i<4;i++){
			tx = x+dx[i];
			ty = y+dy[i];
			if(tx<0 || ty<0 || tx>=N || ty>=N || visited[tx][ty])
				continue;
			visited[tx][ty]=true;
			if(Map[tx][ty]==island_n)
				q.push({tx,ty});
			else if(Map[tx][ty]==0)
				q2.push({tx,ty});
		}
	}

	int sz = 0;
	while(!q2.empty()){
		sz = q2.size();
		cnt++;
		for(int i=0;i<sz;i++){
			x = q2.front().first;
			y = q2.front().second;
			q2.pop();

			for(int j=0;j<4;j++){
				tx = x+dx[j];
				ty = y+dy[j];
				if(tx<0 || ty<0 || tx>=N || ty>=N || visited[tx][ty])
					continue;
				visited[tx][ty] = true;
				q2.push({tx,ty});
				if(Map[tx][ty]!=0){
					i=sz;
					while(!q2.empty())
						q2.pop();
					ans = min(ans,cnt);
					break;
				}
			}
		}
	}




}
void print(){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout << Map[i][j] <<' ';
		}
		cout << '\n';
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(Map,0,sizeof(Map));
	memset(visited_island,false,sizeof(visited_island));

	cin >> N;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> Map[i][j];
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Map[i][j]==1)
				nameTheIsland(i,j);
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Map[i][j]>0 && !visited_island[Map[i][j]]){
				visited_island[Map[i][j]]=true;
				bfs(i,j);
			}
		}
	}

	cout << ans;


	return 0;
}