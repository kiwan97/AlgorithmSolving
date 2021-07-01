#include <iostream>

using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N,K;
	cin >> N >> K;

	long long up,down;

	up = down = 1;

	for(int i=N;i>=(N-K+1);i--){
		up *= i;
		up %= 1000000007;
	}
	for(int i=N;i>0;i--){
		down *= i;
		down %= 1000000007;
	}

	if(up<down)
		

	return 0;
}