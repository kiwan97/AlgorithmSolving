#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int N,M;
bool known[55];
int parent[55];
vector<int> party[55];

int Find(int a){
	if(parent[a]==a)
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b){
	int pa = Find(a);
	int pb = Find(b);
	parent[pb] = pa;
}

bool isUnion(int a,int b){
	return Find(a) == Find(b);
}
bool checkParty(int n){
	int sz = party[n].size();
	for(int i=1;i<=N;i++){
		if(!known[i])
			continue;
		for(int j=0;j<sz;j++){
			if(isUnion(i,party[n][j]))
				return true;
		}
	}
	return false;
}
void init(){
	memset(known,false,sizeof(known));
	for(int i=0;i<55;i++)
		parent[i]=i;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	init();

	cin >> N >> M;
	int t,t2,t3;
	cin >> t;
	for(int i=0;i<t;i++){
		cin >> t2;
		known[t2]=true;
	}

	for(int i=0;i<M;i++){
		cin >> t;
		for(int j=0;j<t;j++){
			cin >> t2;
			party[i].push_back(t2);
			if(j==0){
				t3=t2;
			}else{
				Union(t3,t2);
			}
		}
	}

	int imposs=0;
	for(int i=0;i<M;i++){
		if(checkParty(i))
			imposs++;
	}

	cout << M-imposs;


	return 0;
}