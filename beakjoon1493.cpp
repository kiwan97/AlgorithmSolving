#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int L,W,H;
int N;

int large;
int cube[22];
long long mirimiri[22];
long long powpow[22];
bool flag=false;

int findLen(int l,int w,int h){
	int low = min(l,min(w,h));

	int two=0;
	while(powpow[two]<=low)
		two++;
	two--;
	return two;
}

int calc(int l,int w,int h){
	if(flag)
		return 0;
	if(l<=0 || w<=0 || h<=0)
		return 0;

	long long two = findLen(l,w,h);
	long long ret = 0;
	long long vol = mirimiri[two];

	for(int i=large;i>=0;i--){
		if(cube[i]==0)
			continue;
		long long tmpVol = mirimiri[i];
		if(vol<tmpVol)
			continue;
		long long tt = min(vol/tmpVol,(long long)cube[i]);
		cube[i]-=tt;
		ret+=tt;
		vol -= tmpVol*tt;
	}
	if(vol!=0){
		flag = true;
		return 0;
	}
	ret += calc(l-powpow[two],w,powpow[two]);
	ret += calc(powpow[two],w-powpow[two],powpow[two]);
	ret += calc(l,w,h-powpow[two]);

	return ret;

}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> L >> W >> H;
	cin >> N;
	int A,B;
	large=0;
	while(N--){
		cin >> A >> B;
		cube[A] = B;
		large = max(large,A);
	}
	for(int i=0;i<=20;i++){
		powpow[i] = pow(2,i);
		mirimiri[i] = pow(powpow[i],3);
	}

	int ans = calc(L,W,H);
	if(flag)
		cout << -1;
	else
		cout << ans;

	return 0;
}