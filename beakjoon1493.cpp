#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int L,W,H;
int N;

int cube[22];
bool flag=false;

int findLen(int l,int w,int h){
	int low = min(l,min(w,h));

	int two=0;
	while(pow(2,two)<=low)
		two++;
	two--;
	return pow(2,two);
}

int calc(int l,int w,int h){
	if(l<=0 || w<=0 || h<=0)
		return 0;

	long long len = findLen(l,w,h);
	long long ret = 0;
	long long vol = len*len*len;

	for(int i=20;i>=0;i--){
		if(cube[i]==0)
			continue;
		long long kk = pow(2,i);
		long long tmpVol = kk*kk*kk;
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
	ret += calc(l-len,w,len);
	ret += calc(len,w-len,len);
	ret += calc(l,w,h-len);

	return ret;

}

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);


	cin >> L >> W >> H;
	cin >> N;
	int A,B;

	while(N--){
		cin >> A >> B;
		cube[A] = B;
	}

	int ans = calc(L,W,H);
	if(flag)
		cout << -1;
	else
		cout << ans;

	return 0;
}