#include <iostream>
#include <cstring>

using namespace std;
int N,M,T;
int step[10];
int dp[5001][5001]; // idx: 총합, value: 득점

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while(T--){
		memset(dp,-1,sizeof(dp));
		cin >> N >> M;

		for(int i=0;i<M;i++){
			cin >> step[i];
		}

		dp[0][0] = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<=i && j<=100;j++){
				if(dp[i][j]==-1)
					continue;
				for(int k=0;k<M;k++){
					if(i+j+step[k]<=N && j+step[k]<=100)
						dp[i+j+step[k]][j+step[k]] = max(dp[i+step[k]][j+step[k]],dp[i][j]+step[k]);	
				}
			}
		}
		int ans = -1;
		for(int i=0;i<5001;i++){
			ans = max(ans,dp[N][i]);
		}
		cout << ans << '\n';
	}

	return 0;
}