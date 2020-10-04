#include <iostream>
#include <stack>

using namespace std;

int N;
stack<int> q1;
stack<int> q2;
stack<int> q3;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	int a;

	for(int i=0;i<N;i++){
		cin >> a;
		q3.push(a);
	}
	while(!q3.empty()){
		q1.push(q3.top());
		q3.pop();
	}

	int cur = 1;
	bool flag=false;
	while(!q1.empty() || !q2.empty()){
		if(!q1.empty() && !q2.empty()){
			if(q1.top() == cur){
				q1.pop();
				cur++;
			}else if(q2.top() == cur){
				q2.pop();
				cur++;
			}else{
				q2.push(q1.top());
				q1.pop();
			}
		}else if(!q1.empty()){
			if(q1.top() == cur){
				q1.pop();
				cur++;
			}else{
				q2.push(q1.top());
				q1.pop();
			}
		}else{
			if(q2.top() == cur){
				q2.pop();
				cur++;
			}else{
				flag = true;
				break;
			}
		}
	}
	if(flag){
		cout << "Sad";
	}else{
		cout << "Nice";
	}
	return 0;
}