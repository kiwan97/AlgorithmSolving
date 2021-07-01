#include <iostream>
#include <cstring>
#include <cmath>
#include <utility>
using namespace std;
int N,M,D;
int Map[16][16];
int orgMap[16][16];
int cnt=0;
int ans=0;
pair<int,int> Arc[3];
pair<int,int> Attack[3];

void copyOrg(){
	for(int i=0;i<16;i++){
		for(int j=0;j<16;j++){
			Map[i][j] = orgMap[i][j];
		}
	}
}
void moveForward(){
	for(int i=0;i<M;i++)
		Map[N-1][i]=0;
	for(int i=N-1;i>0;i--){
		for(int j=0;j<M;j++)
			swap(Map[i][j],Map[i-1][j]);
	}
}
int calcDist(int x1,int y1, int x2,int y2){
	return abs(x1-x2)+abs(y1-y2);
}
void makeAttack(){
	int x,y;
	for(pair<int,int>& val : Attack){
		x=val.first; y=val.second;
		if(x==-1 || y==-1)
			continue;
		if(Map[x][y]==0)
			continue;
		Map[x][y]=0;
		cnt++;
	}
}

pair<int,int> findClose(pair<int,int> ark){
	int x,y;
	x = ark.first; y=ark.second;
	int rx,ry;
	int dist=1e9;
	int tmpDist;
	rx=ry=-1;
	for(int j=0;j<M;j++){
		for(int i=N-1;i>=0;i--){
			if(Map[i][j]==1){
				tmpDist = calcDist(i,j,x,y);
				if(tmpDist<=D && dist>tmpDist){
					dist=tmpDist;
					rx=i; ry=j;
				}
			}
		}
	}
	return make_pair(rx,ry);
}
void func(){
	for(int i=0;i<M-2;i++){
		for(int j=i+1;j<M-1;j++){
			for(int k=j+1;k<M;k++){
				Arc[0]=make_pair(N,i);
				Arc[1]=make_pair(N,j);
				Arc[2]=make_pair(N,k);
				cnt=0;
				copyOrg();
				for(int l=0;l<N;l++){
					for(int m=0;m<3;m++){
						Attack[m] = findClose(Arc[m]);
					}
					makeAttack();
					moveForward();	
				}
				ans = max(ans,cnt);
			}
		}
	}	
	
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(Map,0,sizeof(Map));
	memset(orgMap,0,sizeof(orgMap));

	cin >> N >> M >> D;

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> orgMap[i][j];
		}
	}

	func();

	cout << ans << '\n';



	return 0;
}