#include <iostream>
#include <string>
#include <set>
#include <queue>
using namespace std;

string S,T;

string reverse(string s){
	string ret = "";
	int l = s.length();
	for(int i=l-1;i>=0;i--){
		ret+= s[i];
	}
	return ret;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> S >> T;

	string tt = T;
	int l = S.length();
	while(tt.length() > l){
		if(tt[tt.length()-1]=='A')
			tt = tt.substr(0,tt.length()-1);
		else{
			tt = tt.substr(0,tt.length()-1);
			tt = reverse(tt);
		}
	}
	if(tt==S)
		cout << 1;
	else
		cout << 0;

	return 0;
}