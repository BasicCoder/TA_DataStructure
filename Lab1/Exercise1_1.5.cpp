#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>


using namespace std;

int main(){
	char s[100001];
	
	while(scanf("%s", s) != EOF){
		int ret = 0;
		map<char, int> m;
		int start = 1;
		for(int i = 1; i <= strlen(s); ++i){
			char c = s[i-1];
			if(m[c] >= start){
				start = m[c] + 1;
				m[c] = i;
			}else{
				m[c] = i;
				ret = max(ret, i - start + 1);
			}
		}
		printf("%d\n", ret);
	}
} 
