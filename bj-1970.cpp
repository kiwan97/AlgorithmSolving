#include <iostream>
#include <cstring>
using namespace std;

int N;
int cola[1005];
int dp[1005][1005];

int dfs(int from, int to){
	if(from>=to){
		return 0;
	}
	if(dp[from][to]!=-1)
		return dp[from][to];

	int ret = 0;
	// ret = dfs(from+1,to-1) + (cola[from]==cola[to]);
	for(int i=from;i<to;i++){	
		ret = max(ret,dfs(from,i)+dfs(i+1,to));
	}

	return dp[from][to] = ret;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));	

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> cola[i];
	}

	cout << dfs(0,N-1);

	return 0;
}