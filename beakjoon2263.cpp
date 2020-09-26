#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> inorder;
vector<int> postorder;
int cnt = 0;
void func(int is,int ie,int ps,int pe){
	if(is>ie)
		return;
	int iidx=0;
	for(int i=is;i<=ie;i++){
		if(inorder[i] == postorder[pe]){
			iidx = i;
			break;
		}
	}
	cnt++;
	cout << inorder[iidx];
	if(cnt!=n)
		cout << ' ';
	func(is,iidx-1,ps,ps+(iidx-is-1));
	func(iidx+1,ie,ps+(iidx-is),pe-1);
	return;
}
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	inorder.resize(n);
	postorder.resize(n);

	for(int i=0;i<n;i++){
		cin >> inorder[i];
	}

	for(int i=0;i<n;i++){
		cin >> postorder[i];
	}

	func(0,n-1,0,n-1);
	return 0;
}