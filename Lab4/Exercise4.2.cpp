#include <iostream>
#include <string>
#include <vector>

using namespace std;

int minDistance(string word1, string word2){
	int len1 = word1.size();
	int len2 = word2.size();
	
	vector<vector<int>> dp(len1+1, vector<int>(len2+1));
	
	dp[0][0] = 0;
	for(int i =1; i < len1+1; i++)
		dp[i][0] = i;
	for(int j = 1; j < len2+1; j++)
		dp[0][j] = j;
	
	for(int i = 1; i < len1 +1; ++i){
		for(int j = 1; j < len2 +1; ++j){
			if(word1[i -1] == word2[j -1]){
				dp[i][j] = dp[i -1][j -1];
			}else{
				int tmp = 1 + dp[i-1][j-1];
				tmp = min(tmp, 1+dp[i-1][j]);
				tmp = min(tmp, 1+dp[i][j-1]);
				dp[i][j] = tmp;
			}
		}
	}
	return dp[len1][len2];
}

int main(){
	string word1, word2;
	while(cin >> word1 >> word2){
		cout << minDistance(word1, word2) << endl;
	}
}
