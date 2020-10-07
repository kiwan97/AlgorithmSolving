#include <iostream>
#include <string>
using namespace std;

int pi[1000005];
int ans = 0;
void getPi(string P){
	int j = 0;
	int m = P.length();
	for(int i=1;i<m;i++){
		while(j>0 && P[i] != P[j])
			j = pi[j-1];
		if(P[i]==P[j]){
			j++;
			pi[i] = j;
		}
	}
	return;
}
void kmp(string S,string P){
	int j=0;
	int n,m;
	n = S.length();
	m = P.length();
	for(int i=0;i<n;i++){
		while(j>0 && S[i] != P[j]){
			j = pi[j-1];
		}
		if(S[i]==P[j]){
			if(j==m-1){
				ans = 1;
				return;
			}else{
				j++;
			}
		}
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s,p;
	cin >> s >> p;
	getPi(p);
	kmp(s,p);
	cout << ans;

	return 0;
}
