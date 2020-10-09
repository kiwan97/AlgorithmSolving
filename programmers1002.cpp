#include <string>
#include <vector>

using namespace std;

bool check(string s){
	int l = s.length();
	for(int i=0;i<l;i++)
		if(s[i]!=s[0])
			return false;
	return true;
}
int calc(string s){
	int l = s.length();
	for(int i=0;i<l;i++){
		for(int j=0;j<l;j++){
			if()
		}
	}
}
int dist[30];
long long solution(string s) {
    long long answer = -1;
    answer = 0;
    if(check(s))
    	return 0;
    
    int l = s.length();
    int now = 0;
    for(int k=0;k<l;k++){
    	now=0;
    	for(int i=0;i<30;i++)
    		dist[i]=1e9;
	    for(int i=k;i<l;i++){
	    	if(dist[s[i]-'a']==1e9)
	    		dist[s[i]-'a']=i;
	    	for(int j=0;j<26;j++){
	    		if((char)('a'+j) == s[i])
	    			continue;
	    		if(i-dist[j] > now)
	    			now = i-dist[j];
	    		answer += now;
	    	}
	    }
	}

    return answer;
}