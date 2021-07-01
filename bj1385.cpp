#include <iostream>
#include <tuple>
#include <queue>
#include <utility>
using namespace std;

int rooms[3005][3005];
pair<int,int> dp[3005][3005];
int a,b;
vector<tuple<int,int,int>> arrows;
vector<pair<int,int>> arrows2;
pair<int,int> findCor(int val){
	for(int i=0;i<3005;i++){
		for(int j=0;j<3005;j++){
			if(rooms[i][j]==val)
				return make_pair(i,j);
		}
	}
	return make_pair(-1,-1);
}
void dfs(int x,int y){
	cout << "x: "<<x<<", y: "<<y<<'\n';
	if(rooms[x][y]==a){
		cout << a << ' ';
		return;
	}
	dfs(dp[x][y].first, dp[x][y].second);
	cout << rooms[x][y] <<' ';
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	rooms[1500][1500] = 1;
	rooms[1499][1500] = 2;

	arrows.push_back(make_tuple(0,1,0));
	arrows.push_back(make_tuple(1,0,0));
	arrows.push_back(make_tuple(1,-1,0));
	arrows.push_back(make_tuple(0,-1,0));
	arrows.push_back(make_tuple(1,0,1));
	arrows.push_back(make_tuple(-1,1,0));

	arrows2.push_back(make_pair(-1,0));
	arrows2.push_back(make_pair(-1,1));
	arrows2.push_back(make_pair(0,1));
	arrows2.push_back(make_pair(1,0));
	arrows2.push_back(make_pair(1,1));
	arrows2.push_back(make_pair(0,-1));
	for(int i=0;i<3005;i++){
		for(int j=0;j<3005;j++){
			dp[i][j].first = dp[i][j].second = -1;
		}
	}
	int x,y;
	x = 1499; y=1500;
	int idx=2;

	for(int phase=0;idx<=1000000;phase++){
		for(int i=0;i<6;i++){
			for(int k=0;k<=get<2>(arrows[i])+phase;k++){
				x += get<0>(arrows[i]);
				y += get<1>(arrows[i]);
				idx++;
				if(idx>1000000)
					break;
				cout << "x: "<<x<<", y: "<<y << ", idx: "<<idx<<'\n';
				if(x<0 || y<0 || x>=3005 || y>=3005)
					continue;
				rooms[x][y] = idx;
			}
			if(idx>1000000)
				break;
		}
	}	
	

	
	cin >> a >> b;

	pair<int,int> one;
	one = findCor(a);

	queue<pair<int,int>> q;
	q.push(one);

	int tx,ty;
	bool flag=false;

	while(!q.empty()){
		pair<int,int> top = q.front();
		x = top.first; y = top.second;
		q.pop();
		
		for(int i=0;i<6;i++){
			tx = x+arrows2[i].first;
			ty = y+arrows2[i].second;
			if(tx<0 || ty<0 || tx>=3005 || ty>=3005 || (dp[tx][ty].first!=-1 && dp[tx][ty].second!=-1))
				continue;
			dp[tx][ty] = make_pair(x,y);
			q.push({tx,ty});
			if(rooms[tx][ty]==b){
				cout << "!!\n";
				flag=true;
				break;
			}
		}
		if(flag)
			break;
	}
	cout << "tx: "<<tx<<", ty: "<<ty<<'\n';
	dfs(tx,ty);

	return 0;
}