#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

#define offset 10000000000

long long a[10001];

bool compare(long long a, long long b){
	return a > b;
}
int main()
{
	int n, m;
	while(scanf("%d %d ", &n, &m) != EOF){
		for(int i = 0; i < n; ++i){
			scanf("%lld", &a[i]);
		}	
	}
	
	sort(a, a+10001, compare);
	
	for(int i = 0; i < m; ++i){
		printf("%lld", a[i]);
		
		if(i == m-1){
			printf("\n");
		}else{
			printf(" ");
		}
	}
}
