#include <cstdio>

int max(int a, int b){
	return a > b ? a : b;
}
int main(void){

	int n, a[1001], lis[1001], ans;
	scanf("%d", &n);

	for(int i = 1; i<=n; ++i)
		scanf("%d", &a[i]);

	ans = a[1];
	for(int i = 1; i<=n; ++i){
		lis[i] = a[i];
		for(int j = 1; j<=i; ++j){
			if(a[i] > a[j] && lis[i] < lis[j] + a[i]){
				lis[i] = lis[j] + a[i];
				ans = max(ans, lis[i]);
			}
		}
	}

	printf("%d", ans);

	return 0;
}

