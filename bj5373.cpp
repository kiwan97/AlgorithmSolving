#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int n;

char U[9]={
	'w','w','w',
	'w','w','w',
	'w','w','w'
};

char D[9]={
	'y','y','y',
	'y','y','y',
	'y','y','y'
};

char F[9]={
	'r','r','r',
	'r','r','r',
	'r','r','r'
};

char B[9]={
	'o','o','o',
	'o','o','o',
	'o','o','o'
};

char L[9]={
	'g','g','g',
	'g','g','g',
	'g','g','g'
};

char R[9]={
	'b','b','b',
	'b','b','b',
	'b','b','b'
};

//--------------------------------

char U2[9]={
	'w','w','w',
	'w','w','w',
	'w','w','w'
};

char D2[9]={
	'y','y','y',
	'y','y','y',
	'y','y','y'
};

char F2[9]={
	'r','r','r',
	'r','r','r',
	'r','r','r'
};

char B2[9]={
	'o','o','o',
	'o','o','o',
	'o','o','o'
};

char L2[9]={
	'g','g','g',
	'g','g','g',
	'g','g','g'
};

char R2[9]={
	'b','b','b',
	'b','b','b',
	'b','b','b'
};


char* outer_U[12]={
	B+2,B+1,B+0,
	R+2,R+1,R+0,
	F+2,F+1,F+0,
	L+2,L+1,L+0
};
char* outer_D[12]={
	B+6,B+7,B+8,
	L+6,L+7,L+8,
	F+6,F+7,F+8,
	R+6,R+7,R+8
};
char* outer_F[12]={
	U+6,U+7,U+8,
	R+0,R+3,R+6,
	D+6,D+7,D+8,
	L+8,L+5,L+2
};
char* outer_B[12]={
	U+2,U+1,U+0,
	L+0,L+3,L+6,
	D+2,D+1,D+0,
	R+8,R+5,R+2
};
char* outer_L[12]={
	U+0,U+3,U+6,
	F+0,F+3,F+6,
	D+8,D+5,D+2,
	B+8,B+5,B+2
};
char* outer_R[12]={
	U+8,U+5,U+2,
	B+0,B+3,B+6,
	D+0,D+3,D+6,
	F+8,F+5,F+2
};

void innerRightTurn(char inner[]){
	char tmp[9]={' ',};
	tmp[0]=inner[6];
	tmp[1]=inner[3];
	tmp[2]=inner[0];
	tmp[3]=inner[7];
	tmp[4]=inner[4];
	tmp[5]=inner[1];
	tmp[6]=inner[8];
	tmp[7]=inner[5];
	tmp[8]=inner[2];

	for(int i=0;i<9;i++)
		inner[i]=tmp[i];
}
void outerRightTurn(char* outer[]){
	char tmp[12]={' ',};
	tmp[0]= *outer[9];
	tmp[1]= *outer[10];
	tmp[2]= *outer[11];
	tmp[3]= *outer[0];
	tmp[4]= *outer[1];
	tmp[5]= *outer[2];
	tmp[6]= *outer[3];
	tmp[7]= *outer[4];
	tmp[8]= *outer[5];
	tmp[9]= *outer[6];
	tmp[10]= *outer[7];
	tmp[11]= *outer[8];

	for(int i=0;i<12;i++)
		*outer[i]=tmp[i];
}

void innerLeftTurn(char inner[]){
	char tmp[9]={' ',};
	tmp[0]=inner[2];
	tmp[1]=inner[5];
	tmp[2]=inner[8];
	tmp[3]=inner[1];
	tmp[4]=inner[4];
	tmp[5]=inner[7];
	tmp[6]=inner[0];
	tmp[7]=inner[3];
	tmp[8]=inner[6];

	for(int i=0;i<9;i++)
		inner[i]=tmp[i];
}

void outerLeftTurn(char* outer[]){
	char tmp[12]={' ',};
	tmp[0]= *outer[3];
	tmp[1]= *outer[4];
	tmp[2]= *outer[5];
	tmp[3]= *outer[6];
	tmp[4]= *outer[7];
	tmp[5]= *outer[8];
	tmp[6]= *outer[9];
	tmp[7]= *outer[10];
	tmp[8]= *outer[11];
	tmp[9]= *outer[0];
	tmp[10]= *outer[1];
	tmp[11]= *outer[2];

	for(int i=0;i<12;i++){
		*outer[i]=tmp[i];
	}
}

vector<string> order;
string str;
int T;

void executeOrder(string ord){
	char* one;
	char** two;
	if(ord[0]=='U'){
		one = U; two = outer_U;
	}else if(ord[0]=='D'){
		one = D; two = outer_D;
	}else if(ord[0]=='F'){
		one = F; two = outer_F;
	}else if(ord[0]=='B'){
		one = B; two = outer_B;
	}else if(ord[0]=='L'){
		one = L; two = outer_L;
	}else if(ord[0]=='R'){
		one = R; two = outer_R;
	}

	if(ord[1]=='+'){
		innerRightTurn(one);
		outerRightTurn(two);
	}else if(ord[1]=='-'){
		innerLeftTurn(one);
		outerLeftTurn(two);
	}	
}

void init(){
	for(int i=0;i<9;i++){
		U[i]=U2[i];
		D[i]=D2[i];
		F[i]=F2[i];
		B[i]=B2[i];
		L[i]=L2[i];
		R[i]=R2[i];
	}
}
void printU(){
	for(int i=0;i<9;i++){
		cout << U[i];
		if(i%3==2)
			cout << '\n';
	}
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;
	while(T--){
		init();
		int ttt;
		cin >> ttt;

		order.clear();
		while(ttt--){
			cin >> str;
			order.push_back(str);
		}
		
		for(string ss : order){
			executeOrder(ss);
		}
		printU();
	}
	return 0;
}