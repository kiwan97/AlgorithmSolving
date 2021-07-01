#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int N,M,t,tmp;
bool known[55];
vector<int> party[55];
bool before[55];
bool after[55];

bool check(int party_n){
	int sz = party[party_n].size();
	for(int i=0;i<sz;i++)
		if(known[party[party_n][i]])
			return true;
	return false;
}
void addKnown(int party_n){
	int sz = party[party_n].size();
	for(int i=0;i<sz;i++){
		known[party[party_n][i]]=true;
	}
}

bool checkBeforeAfter(){
	for(int i=0;i<55;i++)
		if(before[i]!=after[i])
			return true;

	return false;
}
void copyBeforeAfter(){
	for(int i=0;i<55;i++)
		before[i]=after[i];
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	memset(known,false,sizeof(known));
	memset(before,false,sizeof(before));
	memset(after,false,sizeof(after));

	cin >> N >> M;

	cin >> t;
	for(int i=0;i<t;i++){
		cin >> tmp;
		known[tmp]=true;
	}

	for(int i=0;i<M;i++){
		cin >> t;
		for(int j=0;j<t;j++){
			cin >> tmp;
			party[i].push_back(tmp);
		}
	}

	do{
		copyBeforeAfter();

		for(int i=0;i<M;i++){
			if(check(i)){
				addKnown(i);
				after[i]=true;
			}
		}

	}while(checkBeforeAfter());


	int sum = 0;
	for(int i=0;i<M;i++){
		if(!after[i])
			sum++;
	}
	cout << sum;
	return 0;
}