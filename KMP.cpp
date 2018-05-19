#include <bits/stdc++.h>
using namespace std;

void cal_next(string str, vector<int> &next){
	next[0] = -1;
	int k = -1;
	for(int i = 1; i < str.length(); i ++){
		while(k > -1 && str[k + 1] != str[i]) k = next[k];
		if(str[k + 1] == str[i]) k ++;
		next[i] = k;
	}
}

int main(){
	string s;
	string subs;
	cin >> s;
	cin >> subs;
	vector<int> next(subs.length());
	cal_next(subs, next);
	// for(int i = 0; i < next.size(); i ++) cout << next[i] << " ";
	int k = -1;
	for(int i = 0; i < s.length(); i ++){
		while(k > -1 && subs[k + 1] != s[i]) k = next[k];
		if(subs[k + 1] == s[i]) k ++;
		if(k == subs.length() - 1){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0; 
}
