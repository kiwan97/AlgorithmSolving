#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int permu[8]={1,2,3,4,5,6,7,8};
int N;
int yagu[50][9];
int ground[3];

pair<int,int> doInning(int inning, int idx){
	int threeOut = 0;
	int score=0;
	int taja=0;
	ground[0]=ground[1]=ground[2]=0;

	while(threeOut<3){
		idx%=9;
		if(idx==3){
			taja=0;
		}else{
			if(idx>3){
				taja=permu[idx-1];
			}else{
				taja=permu[idx];
			}
		}

		int status = yagu[inning][taja];
		if(status==0){
			threeOut++;
		}else if(status==1){
			score+=ground[2];
			ground[2] = ground[1];
			ground[1] = ground[0];
			ground[0] = 1;
		}else if(status==2){
			score+=ground[1]+ground[2];
			ground[2] = ground[0];
			ground[1] = 1;
			ground[0] = 0;
		}else if(status==3){
			score += ground[0] + ground[1] + ground[2];
			ground[2] = 1;
			ground[0] = ground[1] = 0;
		}else if(status==4){
			score += ground[0] + ground[1] + ground[2] + 1;
			ground[0] = ground[1] = ground[2] = 0;
		}
		idx++;
	}
	return make_pair(score,idx);
}

int func(){
	int sum = 0;
	int idx=0;
	for(int i=0;i<N;i++){
		auto ret = doInning(i,idx);
		sum += ret.first;
		idx = ret.second;
	}
	return sum;

}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for(int i=0;i<N;i++){
		for(int j=0;j<9;j++){
			cin >> yagu[i][j];
		}
	}

	int ans =0;
	do{
		int ret = func();
		if(ret > ans)
			ans = ret;
	}while(next_permutation(permu,permu+8));

	cout << ans;

	return 0;
}