#include <iostream>

using namespace std;

int N,M;
int arr[11];

int ans = 1e9;
pair<int,int> coin1;
pair<int,int> coin2;
string Map[22];
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int check(pair<int,int>& c1,pair<int,int>& c2){
	if(c1.first < 0 || c1.second < 0 || c1.first >= N || c1.second >= M){
		if(c2.first >=0 && c2.second >=0 && c2.first < N && c2.second < M){
			return 1;
		}
		else
			return -1;
	}else if(c2.first < 0 || c2.second < 0 || c2.first >= N || c2.second >= M){
		if(c1.first >=0 && c1.second >=0 && c1.first < N && c1.second < M){
			return 1;
		}
		else
			return -1;
	}else if(c1.first == c2.first && c1.second == c2.second)
		return -1;
	return 0;
}
void moveIt(pair<int,int>& coin,int dir){
	int tx,ty,x,y;
	x = coin.first; y = coin.second;
	tx = x + dx[dir];
	ty = y + dy[dir];

	if(tx>=0 && ty>=0 && tx<N && ty<M && Map[tx][ty]=='#')
		return;

	coin.first = tx; coin.second = ty;

	return;
}
void print_arr(){
	for(int i=1;i<=10;i++)
		cout << arr[i] << ' ';
	cout << "-------------------------\n";
}
void moveCoin(){
	pair<int,int> t1;
	pair<int,int> t2;
	t1.first = coin1.first;
	t1.second = coin1.second;
	t2.first = coin2.first;
	t2.second = coin2.second;

	int litmus;
	int i;
	for(i=1;i<=10;i++){
		moveIt(t1,arr[i]);
		moveIt(t2,arr[i]);

		litmus = check(t1,t2);
		if(litmus==1){
			ans = min(ans,i);
			return;
		}else if(litmus==-1)
			return;
	}
	
	return;
}
void dfs(int idx,int now){
	if(idx==10){
		moveCoin();
		return;
	}

	for(int i=0;i<4;i++){
		arr[idx+1] = i;
		dfs(idx+1,i);
	}

	return;
}
int main(){
	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> Map[i];
	bool flag = false;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(Map[i][j] == 'o'){
				if(flag){
					coin2.first = i; coin2.second = j;
				}else{
					coin1.first = i; coin1.second = j;
					flag=true;
				}
				Map[i][j] = '.';
			}
		}
	}
	for(int i=0;i<4;i++){
		arr[1]=i;
		dfs(1,i);
	}
	if(ans==1e9)
		cout << -1;
	else
		cout << ans;
	return 0;
}
