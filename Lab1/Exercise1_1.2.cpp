#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int main(){
	char s[100001];
	
	while(scanf("%s", s) != EOF){
		vector<int> m(256, -1);
		int res = 0, left = -1;
		for(int i = 0; i < strlen(s); ++i){
			left = max(left, m[s[i]]);
			m[s[i]] = i;
			res = max(res, i - left);
		}
		printf("%d\n", res);
	}
	
}
