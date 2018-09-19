#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <set>


using namespace std;

int main(){
	char s[100001];
	
	while(scanf("%s", s) != EOF){
		set<char> t;
		int res = 0, left = 0, right = 0;
		while(right < strlen(s)){
			if(t.find(s[right]) == t.end()){
				t.insert(s[right++]);
				res = max(res, (int)t.size());
			}else{
				t.erase(s[left++]);
			}
		}
		printf("%d\n", res);
	}
	
}
