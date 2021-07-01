#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <cstring>

using namespace std;
int N,M,ans;
vector<pair<int,int>> pairs;
vector<int> permu;

string toString(int a){
	string ret = "";
	while(a){
		int t = a%10;
		ret += (char)(t+'0');
		a/=10;
	}
	return ret;
}

string hash1(int one,int two){
	if(one>two)
		swap(one,two);
	return toString(one)+"*"+toString(two);
}



int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	set<string> s;

	ans=0;
	

	for(int i=0;i<M;i++){
		int one,two;
		cin >> one >> two;
		s.insert(hash1(one,two));
	}

	for(int a=1;a<=N-2;a++){
		for(int b=a+1;b<=N-1;b++){
			if(s.find(hash1(a,b))!=s.end())
				continue;
			for(int c=b+1;c<=N;c++){
				if(s.find(hash1(a,c))!=s.end() || s.find(hash1(b,c))!=s.end())
					continue;
				ans++;
			}
		}
	}


	cout << ans;
	return 0;
}