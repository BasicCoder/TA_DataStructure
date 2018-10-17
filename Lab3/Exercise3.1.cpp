#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

bool checkInclusion(string &s1, string &s2){
	char characters1[256] = {0};
	int len1 = s1.length();
	for(int i = 0; i < len1; ++i){
		characters1[s1[i]] += 1;
	}
	
	char characters2[256] = {0};
	for(int i = 0, j = i + s1.size(); j <= s2.size(); ++i, ++j){
		for(int k = i; k < j; ++k){
			if(characters1[s2[k]] == 0) break;
			else characters2[s2[k]] += 1;
		}
		
		for(int k = 0; k < 256; ++k){
			if(characters1[k] == characters2[k]){
				if(k == 255) return true;
				else characters2[k] = 0;
			}else if(k < 255){
				for(int l = k; l < 256; l++){
					characters2[l] = 0;
				}
				break; 
			}
		}
	}
}

int main(){
	string s1, s2;
	while(cin >> s1 >> s2){
		if(checkInclusion(s1, s2)){
			printf("True\n");
		}else{
			printf("False\n");
		}
	}
	
} 
