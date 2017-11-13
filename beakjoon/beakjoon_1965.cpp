#include <cstdio>

int max(int a, int b){
	return a > b ? a : b;
}
int main(void){


	int n, arr[1001], lis[1001], ans;
	scanf("%d", &n);
	for(int i = 1; i<=n; ++i) 
		scanf("%d", &arr[i]);

	ans = 1;
	for(int i = 1; i<=n; ++i){
		lis[i] = 1;
		for(int j = 1; j<=i; ++j){
			if(arr[i] > arr[j] && lis[i] < lis[j]+1){
				lis[i] = lis[j] + 1;
				ans = max(ans, lis[i]);
			}
		}
	}

	printf("%d", ans);
	return 0;
}

