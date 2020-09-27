#include <iostream>

using namespace std;

int N;
int dp[(1<<15)+1][5];
int main(){

	for(int i=1;i*i<=(1<<15);i++){
		dp[i*i][1] = 1;
	}
	for(int i=1;i<=(1<<15);i++){
		for(int j=1;i-j*j>0;j++){
			for(int k=1;k<4;k++){
				dp[i][k+1] += dp[i-j*j][k];
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