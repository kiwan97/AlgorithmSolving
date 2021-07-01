#include <iostream>
#include <string>

using namespace std;

int T,n;
char cube[6][4][4] = { {"www","www","www"},
						{"yyy","yyy","yyy"},
						{"rrr","rrr","rrr"},
						{"ooo","ooo","ooo"},
						{"ggg","ggg","ggg"},
						{"bbb","bbb","bbb"}
					};
char cube2[6][4][4];
void init(){
	for(int i=0;i<6;i++){
		for(int j=0;j<4;j++){
			for(int k=0;k<4;k++){
				cube2[i][j][k] = cube[i][j][k];
			}
		}
	}
	return;
}
int main(){
	cin >> T;
	while(T--){
		init();
		
	}

	return 0;
}