#include <iostream>
#include <vector>
using namespace std;

int arr[1000005];

int func(int N,int zari){

	int idx=0;
	while(N){
		arr[idx++] = N%zari;
		N/=zari;
	}
	int ans = 1;
	for(int i=0;i<idx;i++){
		if(arr[i]!=0)
			ans *= arr[i];
	}
	return ans;
}
vector<int> solution(int N) {
    vector<int> answer;

    int one,two;
    two = 0;
    for(int i=2;i<10;i++){
    	int res = func(N,zari);
    	if(res>=two){
    		one = i;
    		two = res;
    	}
    }

    answer.push_back(one);
    answer.push_back(two);
    
    return answer;
}
int main(){

	int N;
	cin >> N;

	

	return 0;
}