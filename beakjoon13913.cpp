#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int parents[110005];

int N,K;
void recur(int cc){
	if(parents[cc]==cc){
		cout << cc;
		return;
	}
	recur(parents[cc]);
	cout << ' ' << cc;
	return;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(parents,-1,sizeof(parents));

	cin >> N >> K;

	parents[N]=N;
	queue<int> q;
	q.push(N);
	int steps = -1;
	while(!q.empty()){
		steps++;
		int sz = q.size();
		while(sz--){
			int x = q.front();
			if(x==K){
				cout << steps << '\n';
				recur(K);
				return 0;
			}
			q.pop();

			if(x-1>=0 && parents[x-1]==-1){
				parents[x-1] = x;
				q.push(x-1);
			}
			if(x+1<=110000 && parents[x+1]==-1){
				parents[x+1] = x;
				q.push(x+1);
			}
			if(2*x<=110000 && parents[2*x]==-1){
				parents[2*x] = x;
				q.push(2*x);
			}
		}
	}

	return 0;
}