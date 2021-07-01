#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <utility>
using namespace std;

int N,M,P;
int S[10];
int counts[10];
char Map[1005][1005];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
queue<pair<int,int>> q[10];
bool makeBoundary(int idx){
	int sz;
	int x,y,tx,ty;
	bool flag=false;
	for(int k=0;k<S[idx] && !q[idx].empty();k++){
		sz = q[idx].size();
		flag=false;
		while(sz--){
			x = q[idx].front().first;
			y = q[idx].front().second;
			q[idx].pop();

			for(int i=0;i<4;i++){
				tx = x+dx[i];
				ty = y+dy[i];
				if(tx<0 || tx>=N || ty<0 || ty>=M || Map[tx][ty]!='.')
					continue;
				flag=true;
				Map[tx][ty] = (char)('0'+idx);
				q[idx].push({tx,ty});
			}
		}
	}
	return flag;
}

bool func(){
	bool flag = false;
	for(int i=1;i<=P;i++){
		flag |= makeBoundary(i);
	}
	return flag;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> P;

	for(int i=1;i<=P; i++){
		cin >> S[i];
	}
	cin.ignore();
	for(int i=0;i<N;i++){
		cin.getline(Map[i], 1005);
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(Map[i][j]>='1' && Map[i][j]<='9')
				q[Map[i][j]-'0'].push({i,j});
		}
	}

	while(func());
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			counts[Map[i][j]-'0']++;
		}
	}
	for(int i=1;i<=P;i++){
		cout << counts[i] << ' ';
	}
	return 0;
}