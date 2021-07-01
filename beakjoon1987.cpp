#include <iostream>
#include <queue>

using namespace std;

int R,C;
string Map[22];
int dx[] ={0,0,1,-1};
int dy[] = {1,-1,0,0};
int tx,ty;

struct Info{
	int x;
	int y;
	int before;
};
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> R >> C;
	for(int i=0;i<R;i++){
		cin >> Map[i];
	}

	queue<Info> q;
	Info info,tmp;
	info.x = info.y = 0;
	info.before = (1<<(Map[0][0]-'A'));
	q.push(info);
	int ans = 0;
	while(!q.empty()){
		int sz= q.size();
		ans++;
		for(int j=0;j<sz;j++){
			info = q.front();
			q.pop();
			for(int i=0;i<4;i++){
				tx = info.x + dx[i];
				ty = info.y + dy[i];
				int history = info.before;
				if(tx<0 || ty<0 || tx>=R || ty>=C|| history & (1<<(Map[tx][ty]-'A')))
					continue;
				history |= (1<<(Map[tx][ty]-'A'));
				tmp.x = tx; tmp.y = ty; tmp.before = history;
				q.push(tmp);
			}
		}
	}
	cout << ans;
	return 0;
}