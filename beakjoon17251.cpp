#include <iostream>

using namespace std;

int L[1000005],R[1000005],arr[1000005];
int N;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for(int i=0;i<N;i++)
		cin >> arr[i];


	int koko = 0;

	for(int i=0;i<N-1;i++){
		if(koko<arr[i])
			koko=arr[i];
		L[i] = koko;
	}

	koko = 0;
	for(int i=N-1;i>0;i--){
		if(koko<arr[i])
			koko=arr[i];
		R[i] = koko;
	}
	int hong = 0;
	int chung = 0;
	for(int i=0;i<N-1;i++){
		if(L[i]>R[i+1])
			hong++;
		else if(L[i]<R[i+1])
			chung++;
	}
	if(hong==chung)
		cout << 'X';
	else if(hong > chung)
		cout << 'R';
	else
		cout << 'B';

	return 0;
}