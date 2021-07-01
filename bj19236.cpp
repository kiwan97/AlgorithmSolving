#include <iostream>
#include <utility>

using namespace std;

pair<int,int> Mat[4][4];
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,-1,-1,-1,0,1,1,1};

void copyToTmp(pair<int,int> tmp[][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			tmp[i][j] = Mat[i][j];
		}
	}
}
void copyToMat(pair<int,int> tmp[][4]){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			Mat[i][j] = tmp[i][j];
		}
	}
}
bool check(int x,int y){
	return (x>=0 && x<4 && y>=0 && y<4);
}
void moveOne(int x,int y,int dir, int shark_x, int shark_y){
	int tx,ty;
	while(true){
		tx = x+dx[dir-1];
		ty = y+dy[dir-1];
		if(check(tx,ty) && !(tx==shark_x && ty==shark_y))
			break;
		dir++;
		if(dir==9)
			dir=1;
	}
	Mat[x][y].second = dir;

	swap(Mat[tx][ty],Mat[x][y]);
}
void moveAll(int shark_x, int shark_y){
	bool flag;
	for(int k=1;k<=16;k++){
		flag = false;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(Mat[i][j].first==k){
					moveOne(i,j, Mat[i][j].second, shark_x, shark_y);
					flag=true;
					break;
				}
			}
			if(flag)
				break;
		}
	}
}
int dfs(int x,int y, int dir){
	pair<int,int> tmp[4][4];
	copyToTmp(tmp);
	int sum = 0;
	while(true){
		x += dx[dir-1];
		y += dy[dir-1];
		if(!check(x,y))
			break;
		if(Mat[x][y].first==0)
			continue;
		int num = Mat[x][y].first;
		Mat[x][y].first = 0;
		moveAll(x,y);
		sum = max(sum,dfs(x,y,Mat[x][y].second)+num);
		copyToMat(tmp);
	}
	return sum;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			cin >> Mat[i][j].first >> Mat[i][j].second;
		}
	}

	int ans = Mat[0][0].first;
	Mat[0][0].first = 0;
	moveAll(0,0);

	ans += dfs(0,0,Mat[0][0].second);
	
	cout << ans;
	return 0;
}