#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string longestPalindrome(string s){
	if(s.empty())return "";
	if(s.size()==1) return s;
	int start = 0, maxlength =1;
	for(int i = 0; i < s.size(); ++i){
		for(int j = i +1; j < s.size(); ++j){
			int temp1, temp2;
			for(temp1 = i, temp2 = j; temp1 < temp2; ++temp1, --temp2){
				if(s[temp1] != s[temp2])
					break;
			}
			if(temp1 >= temp2 && j -i+1 > maxlength){
				maxlength = j-i+1;
				start = i;
			}
		}
	}
	return s.substr(start, maxlength);
}


int main(){
	int N;
	string s;
	while(scanf("%d", &N)!=EOF){
		cin >> s;
		cout << longestPalindrome(s) << endl;
	}
}
