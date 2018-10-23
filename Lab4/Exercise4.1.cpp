#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

void dfs(string s, int n, string out, vector<string>& res){
	if(n == 4){
		if(s.empty())res.push_back(out);
	}else{
		for(int k = 1; k < 4; ++k){
			if(s.size() < k) break;
			int val = atoi(s.substr(0, k).c_str());
			if(val > 255 || k != to_string(val).size()) continue; 
			dfs(s.substr(k), n+1, out+s.substr(0,k) + (n==3? "":"."), res);
		}
	}
}

char s0[10001];
int main(){
	string s;
	while(scanf("%s", s0) != EOF){
		vector<string> res;
		s = s0;
		dfs(s, 0, "", res);
		for(int i = 0; i < res.size(); ++i){
			cout << res[i] << endl;
		}
	}
}
