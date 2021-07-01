#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int R,C;
int N;
vector<string> Map;
int nxtMap[105][105];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
void nxtMap2Map(){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			if(nxtMap[i][j]!=0)
				Map[i][j] = 'x';
			else
				Map[i][j] = '.';
		}
	}
}
void printMap(){
	for(int i=0;i<R;i++){
		cout << Map[i] << '\n';
	}
}
void printnxtMap(){
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++)
			cout << nxtMap[i][j];
		cout << '\n';
	}
}
int findClose(int num){
	int rt = 1e9;
	vector<int> all;
	for(int col=0;col<C;col++){
		int idx = R-1;
		int cnt=0;
		all.clear();
		for(int i=0;i<R;i++)
			if(nxtMap[i][col]==num)
				all.push_back(i);

		for(int i=0;i<all.size();i++){
			idx = all[i];
			idx++;
			cnt = 0;
			while(idx<R && nxtMap[idx][col]==0){
				cnt++;
				idx++;
			}
			if(idx==R){
				rt = min(rt,cnt);
			}
			else if(idx<R && nxtMap[idx][col]!=num)
				rt = min(rt,cnt);
		}
	}
	return rt;
}

void moveCluster(int num,int val){
	if(val==0)
		return;
	for(int col=0;col<C;col++){
		int idx = R-1;
		while(idx>=0 && nxtMap[idx][col]!=num)
			idx--;
		
		while(idx>=0){
			if(nxtMap[idx][col]==num){
				nxtMap[idx+val][col] = num;
				nxtMap[idx][col] = 0;
			}
			idx--;
		}
	}
}
void attack(int row,bool isLeft){
	string line = Map[row];

	int idx;
	if(isLeft){
		idx = 0;
		while(idx<C && line[idx]=='.')
			idx++;
		if(idx<C)
			line[idx]='.';

	}else{
		idx=C-1;
		while(idx>=0 && line[idx]=='.')
			idx--;
		if(idx>=0)
			line[idx]='.';
	}
	Map[row] = line;
}
bool dfs(int r,int c,int num){
	bool rt = false;
	nxtMap[r][c]=num;
	if(r==R-1)
		rt=true;
	for(int i=0;i<4;i++){
		int tr = r+dx[i];
		int tc = c+dy[i];
		if(tr<0 || tc<0 || tr>=R || tc>=C || Map[tr][tc]=='.' || nxtMap[tr][tc]!=0)
			continue;
		nxtMap[tr][tc]=num;
		rt |= dfs(tr,tc,num);
	}
	return rt;
}
bool bfs(int r,int c, int num){
	bool rt = false;

	queue<pair<int,int> > q;
	q.push({r,c});
	if(r==R-1)
		rt=true;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		for(int i=0;i<4;i++){
			int tr = t.first + dx[i];
			int tc = t.second + dy[i];
			if(tr<0 || tc<0 || tr>=R || tc>=C || Map[tr][tc]=='.' || nxtMap[tr][tc]!=0)
				continue;
			nxtMap[tr][tc]=num;
			if(tr==R-1)
				rt = true;
			q.push({tr,tc});
		}
	}
	return rt;

}

void Command(){
	int num = 0;
	int fallen;
	for(int row=0;row<R;row++){
		for(int col=0;col<C;col++){
			if(Map[row][col]=='x' && nxtMap[row][col] == 0){
				nxtMap[row][col] = ++num;
				if(!bfs(row,col,num)){
					fallen = num;
				}
			}
		}
	}
	moveCluster(fallen,findClose(fallen));
	nxtMap2Map();
}


void initnxtMap(){
	memset(nxtMap,0,sizeof(nxtMap));
}


int main(){

	cin >> R >> C;
	Map.resize(R);
	for(int i=0;i<R;i++){
		cin >> Map[i];
	}
	initnxtMap();
	Command();
	cin >> N;
	int cmd;
	bool isLeft;
	for(int i=0;i<N;i++){
		cin >> cmd;
		if(i%2==0)
			isLeft=true;
		else
			isLeft=false;

		attack(R-cmd,isLeft);
		initnxtMap();
		Command();
	}

	printMap();
	return 0;
}