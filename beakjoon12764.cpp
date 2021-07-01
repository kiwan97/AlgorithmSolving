#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int N,P,Q;
vector<pair<int,int> > v;
priority_queue<int> pq;
int schedule[1000005];
int cnt[100005];
int main(){

	cin >> N;
	int end = 0;
	for(int i=0;i<N;i++){
		pq.push(-(i+1));
		cin >> P >> Q;
		end = max(end,Q);
		v.push_back({P,Q});
	}
	sort(v.begin(),v.end());

	int idx = 0;
	int ans = 0;
	for(int i=0;i<=end;i++){
		if(schedule[i]!=0)
			pq.push(-schedule[i]);
		if(v[idx].first == i){
			schedule[v[idx].second] = -pq.top();
			ans = max(ans,-pq.top());
			cnt[-pq.top()]++;
			pq.pop();
			idx++;
		}
	}
	cout << ans << '\n';
	for(int i=1;i<=ans;i++)
		cout << cnt[i] <<' ';


	return 0;

}