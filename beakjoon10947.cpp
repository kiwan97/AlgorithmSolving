#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main(){

	vector<int> v;
	v.resize(45,0);
	for(int i=39;i<45;i++)
		v[i] = 1;
	
	do{
		int cnt=0;
		for(int i=0;i<45;i++){
			if(v[i]){
				cout << i+1;
				cnt++;
				if(cnt!=6)
					cout<<' ';
			}
		}
		cout << '\n';
	}while(next_permutation(v.begin(),v.end()));

	return 0;
}