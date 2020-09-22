#include <iostream>
#include <map>

using namespace std;

int T,n,m;
int A[1005];
int B[1005];

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> A[i];
	

	cin >> m;
	for(int i=0;i<m;i++)
		cin >> B[i];
	

	map<int,int> Map;

	int sum1,sum2;
	sum1 = 0;
	for(int i=0;i<n;i++){
		sum1 += A[i];
		sum2 = 0;
		if(Map.find(sum1)==Map.end())
			Map.insert({sum1,1});
		else
			Map[sum1] = Map[sum1]+1;

		for(int j=0;j<i;j++){
			sum2 += A[j];
			if(Map.find(sum1-sum2)==Map.end())
				Map.insert({sum1-sum2,1});
			else
				Map[sum1-sum2] = Map[sum1-sum2]+1;	
		}
	}

	long long ans = 0;
	sum1 = 0;
	for(int i=0;i<m;i++){
		sum1 += B[i];
		sum2 = 0;
		if(Map.find(T-sum1)!=Map.end())
			ans += Map[T-sum1];

		for(int j=0;j<i;j++){
			sum2 += B[j];
			if(Map.find(T-(sum1-sum2))!=Map.end())
				ans += Map[T-(sum1-sum2)];
		}
	}

	cout << ans;

	return 0;
}