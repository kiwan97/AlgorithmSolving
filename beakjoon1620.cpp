#include <iostream>
#include <map>
#include <vector>

using namespace std;
int N,M;
vector<string> pkm;
map<string,int> pkm2[30];

int makeItInt(string s){
	int ret = 0;
	for(int i=0;i<s.length();i++){
		ret *=10;
		ret += (s[i]-'0');
	}
	return ret;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N >> M;
	string name;
	pkm.push_back("!");
	for(int i=1;i<=N;i++){
		cin >> name;
		pkm.push_back(name);
		pkm2[name[0]-'A'].insert({name,i});
	}

	for(int i=0;i<M;i++){
		cin >> name;
		if(name[0]>='A' && name[0]<='Z'){
			cout << pkm2[name[0]-'A'].find(name)->second << '\n';
		}else{
			cout << pkm[makeItInt(name)] << '\n';
		}
	}
	return 0;
}