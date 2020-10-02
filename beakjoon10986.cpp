#include <iostream>

using namespace std;

int N,M;
int arr[1000005];
long long sum = 0;
int cnt[1005];
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for(int i=0;i<N;i++)
		cin >> arr[i];

	long long ans = 0;
	cnt[0]=1;
	for(int i=0;i<N;i++){
		sum += arr[i];
		ans += cnt[sum%M];
		cnt[sum%M]++;
	}

	cout << ans;
	return 0;
}