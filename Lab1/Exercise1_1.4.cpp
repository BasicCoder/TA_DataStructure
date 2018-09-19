#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <unordered_map>


using namespace std;

int main(){
	char s[100001];
	
	while(scanf("%s", s) != EOF){
		int res = 0, left = 0, i = 0, n = strlen(s);
		unordered_map<char, int> m;
		for(int i = 0; i < n; ++i){
			left = max(left, m[s[i]]);
			m[s[i]] = i +1;
			res = max(res, i - left + 1);
		}
		printf("%d\n", res);
	}
	
}
