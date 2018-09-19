#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>

using namespace std;

int main(){
	char s[100001];
	
	while(scanf("%s", s) != EOF){
		int m[256] = {0}, res = 0, left = 0;
		for(int i = 0; i < strlen(s); ++i){
			if(m[s[i]] == 0 || m[s[i]] < left){
				res = max(res, i - left +1);
			}else{
				left = m[s[i]];
			}
			m[s[i]] = i + 1;
		}
		printf("%d\n", res);
	}
	
}
