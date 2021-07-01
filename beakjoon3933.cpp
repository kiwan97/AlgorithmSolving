#include <iostream>

using namespace std;

int N;
int dp[(1<<15)+1][5];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	for(int i=1;i*i<=(1<<15);i++){
		dp[i*i][1] = 1;
		for(int j=1;j+i*i<=(1<<15);j++){
			for(int k=1;k<4;k++){
				dp[j+i*i][k+1] += dp[j][k];
			}
		}
	}

	while(true){
		cin >> N;
		if(!N)
			break;
		cout << dp[N][1] + dp[N][2] + dp[N][3] + dp[N][4] << '\n';
	}
	return 0;
}