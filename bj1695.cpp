#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[5005][5005];
int arr[5005];
int N;

int dfs(int left,int right){
	if(left>=right)
		return 0;
	if(dp[left][right]!=-1)
		return dp[left][right];
	if(arr[left]==arr[right])
		return dp[left][right] = dfs(left+1,right-1);
	return dp[left][right] = min(dfs(left+1,right),dfs(left,right-1))+1;
}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(dp,-1,sizeof(dp));

	cin >> N;

	for(int i=0;i<N;i++){
		cin >> arr[i];
	}

	cout << dfs(0,N-1);


	return 0;
}