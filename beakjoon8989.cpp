#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
int N;
string times;
double getAngle(int hh,int mm){
	double thh = (double)(hh%12);
	double tmm = (double)mm;

	double angle1 = thh*30 + tmm*0.5;
	double angle2 = tmm*6;

	double t1 = angle1>angle2? angle1-angle2:angle2-angle1;

	return min(t1,360-t1);
}
int str2int(string str){
	return (str[0]-'0')*10 + str[1]-'0';
}
bool comp2(pair<string,double>& a,pair<string,double>& b){
	if(a.second==b.second)
		return a.first < b.first;
	else
		return a.second < b.second;
}
vector<pair<string,double> > v;
int main(){

	cin >> N;
	while(N--){
		v.clear();
		for(int i=0;i<5;i++){
			cin >> times;
			v.push_back({times,getAngle(str2int(times.substr(0,2)),str2int(times.substr(3,2)))});
		}
		sort(v.begin(),v.end(),comp2);
		// for(int i=0;i<5;i++)
		// 	cout << v[i].first << ", "<<v[i].second << '\n';
		// cout << '\n';
		cout << v[2].first << '\n';
	}

	return 0;
}