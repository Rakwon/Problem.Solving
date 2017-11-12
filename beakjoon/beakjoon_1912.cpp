#include <cstdio>

int max(int a, int b){
	return a > b ? a : b;
}
int main(void){

	int n, num[100010];
	scanf("%d", &n);

	for(int i = 0 ; i< n; ++i){
		scanf("%d", &num[i]);
	}

	int ans = num[0], cur_sum = num[0];

	for(int i = 1; i<n; ++i){

		cur_sum = max(cur_sum + num[i], num[i]);
		ans = max(ans, cur_sum);
	}

	printf("%d", ans);
	return 0;
}

