#include <iostream>
#include <cstring>
using namespace std;

int N;
int cola[1005];
int dp[1005][1005];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,0,sizeof(dp));	

	cin >> N;
	for(int i=0;i<N;i++){
		cin >> cola[i];
		dp[i][i]=0;
	}

	for(int i=0;i<N;i+=2){
		for(int j=0;j+i<N;j++){
			int end = i+j;
			dp[j][end] = dp[j+1][end-1] + (cola[j]==cola[end]);
			for(int k=j;k<end;k++)
				dp[j][end] = max(dp[j][end],dp[j][k]+dp[k+1][end]);
		}
	}
	cout << dp[0][N-1];

	return 0;
}