#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
int N;
int population[11];
bool adj[11][11];
bool visited[11];
vector<int> permu;

void dfs(int idx, int color){
	visited[idx]=true;
	for(int i=1;i<=N;i++){
		if(idx!=i && adj[idx][i] && !visited[i] && permu[idx-1] == color){
			dfs(i,color);
		}
	}
}
bool checkAllVisited(int color){
	for(int i=0;i<permu.size();i++){
		if(permu[i]==color && !visited[i+1])
			return false;
	}
	return true;
}

int getSum(int color){
	int sum = 0;
	for(int i=0;i<permu.size();i++){
		if(permu[i]==color){
			sum += population[i+1];
		}
	}
	return sum;
}

int func(){
	memset(visited,false,sizeof(visited));

	int sum0,sum1;
	//color: 0
	int idx;
	for(idx=1;idx<=N;idx++)
		if(permu[idx-1]==0)
			break;
	
	dfs(idx,0);
	if(checkAllVisited(0)){
		sum0 = getSum(0);
	}else{
		return 987654321;
	}

	memset(visited,false,sizeof(visited));
	//color: 1
	for(idx=1;idx<=N;idx++)
		if(permu[idx-1]==1)
			break;
	dfs(idx,1);
	if(checkAllVisited(1)){
		sum1 = getSum(1);
	}else{
		return 987654321;
	}
	return abs(sum0-sum1);
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	memset(adj,false,sizeof(adj));

	cin >> N;
	for(int i=1;i<=N;i++){
		cin >> population[i];
	}
	int cnt, node;
	for(int i=1;i<=N;i++){
		cin >> cnt;
		for(int j=0;j<cnt;j++){
			cin >> node;
			adj[i][node]=true;
		}
	}

	int ans = 987654321;
	for(int i=1;i<N;i++){
		permu.clear();
		int j;
		for(j=1;j<=i;j++)
			permu.push_back(0);
		for(;j<=N;j++)
			permu.push_back(1);
		do{
			ans = min(ans,func());
		}while(next_permutation(permu.begin(),permu.end()));
	}
	if(ans==987654321)
		cout << -1;
	else
		cout << ans;

	return 0;
}