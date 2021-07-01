#include <iostream>

using namespace std;

int originMat[11][11];
int Mat[11][11];
int cnt[11];

void copyOriginMat(){
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			Mat[i][j] = originMat[i][j];
		}
	}
}
bool checkPossible(int x,int y,int len){
	if(x+len-1 >= 10 || y+len-1 >= 10)
		return false;
	for(int tx=x;tx<=x+len-1;tx++){
		for(int ty=y;ty<=y+len-1;ty++){
			if(Mat[tx][ty] == 0)
				return false;
		}
	}
	return true;
}
void paint(int x,int y,int len){
	if(x+len-1 >= 10 || y+len-1 >= 10)
		return;
	for(int tx=x;tx<=x+len-1;tx++){
		for(int ty=y;ty<=y+len-1;ty++){
			if(Mat[tx][ty]==0)
				Mat[tx][ty] = 1;
			else
				Mat[tx][ty] = 0;
		}
	}
}
int dfs(int x,int y){
	if(x>=10)
		return 0;
	if(y>=10)
		return dfs(x+1,0);
	if(Mat[x][y]==0)
		return dfs(x,y+1);

	int ret = 987654321;
	for(int len=1;len<=5;len++){
		if(cnt[len]<5 && checkPossible(x,y,len)){
			paint(x,y,len);
			cnt[len]++;
			ret = min(ret,dfs(x,y+1)+1);
			paint(x,y,len);
			cnt[len]--;
		}
	}
	return ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	bool flag =true;
	for(int i=0;i<10;i++)
		for(int j=0;j<10;j++){
			cin >> Mat[i][j];
			if(Mat[i][j]==1)
				flag = false;
		}

	if(flag){
		cout << 0; return 0;
	}
	int ans = dfs(0,0);
	if(ans>=987654321)
		cout << -1;
	else
		cout << ans;
	return 0;
}