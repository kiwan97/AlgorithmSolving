#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

int N,M;
int Map[11][11];
int Map2[11][11];
bool Map3[11][11];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool visited[2][11][11];
struct Info{
	int x;
	int y;
	bool dari;
};
void init(){
	for(int i=0;i<2;i++){
		for(int j=0;j<11;j++){
			for(int k=0;k<11;k++)
				visited[i][j][k] = false;
		}
	}
}
bool makeItwhite(int x,int y){
	bool hori,vert;
	hori = vert = false;

	if(x-1>=0 && Map[x-1][y]!=1)
		hori = true;
	if(x+1<N && Map[x+1][y]!=1)
		hori = true;
	if(y-1>=0 && Map[x][y-1]!=1)
		vert = true;
	if(y+1<N && Map[x][y+1]!=1)
		vert = true;

	return hori && vert;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> Map[i][j];
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(Map[i][j]!=1 && makeItwhite(i,j))
				Map2[i][j] = 2;
		}
	}

	queue<Info> q;
	Info info;
	info.x = info.y = 0;
	info.dari = false;

	q.push(info);
	int sec = 0;
	while(!q.empty()){
		int sz = q.size();
		init();
		sec++;
		while(sz--){
			auto t = q.front();
			q.pop();
			int x,y;
			bool dari;
			x = t.x; y = t.y; dari = t.dari;
			int tx,ty;
			if(Map[x][y]==1 && !visited[dari==false? 0:1][x][y]){
				visited[dari==false? 0:1][x][y] = true;
				q.push(t);
			}
			for(int i=0;i<4;i++){
				tx = x + dx[i];
				ty = y + dy[i];
				if(tx==N-1 && ty==N-1){
					cout << sec;
					return 0;
				}
				if(tx<0 || ty<0 || tx>=N || ty>=N || (dari && Map[tx][ty]==0) || Map2[tx][ty]==2 || visited[dari==false? 0:1][tx][ty])
					continue;
				if(Map[x][y] == 1 && Map[tx][ty]==0 && !dari && sec%M == 0){
					info.x = tx; info.y = ty; info.dari = true;
					q.push(info);
					visited[dari==false? 0:1][tx][ty] = true;
				}
				if(Map[tx][ty]==1){
					info.x = tx; info.y =ty; info.dari = dari;
					q.push(info);
					visited[dari==false? 0:1][tx][ty] = true;
				}else if(Map[tx][ty]>1 && Map[x][y]==1 && sec%Map[tx][ty] == 0){
					info.x = tx; info.y = ty; info.dari = dari;
					q.push(info);
					visited[dari==false? 0:1][tx][ty] = true;
				}
			}

		}
	}



	return 0;
}