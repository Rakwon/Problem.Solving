#include <cstdio>
int max(int a, int b){
	return a > b  ? a : b;
}
int main(void){

	int n, num[1001], lis[1001], ans = 1;
	scanf("%d", &n);

	for(int i = 1; i<=n; scanf("%d", &num[i++]));

	lis[0] = lis[1] = 1;

	for(int i = 2; i<=n; ++i){
		lis[i] = 1;
		for(int j = 1; j<i; ++j){
			if(num[i] > num[j] && lis[i] < lis[j] + 1){
				lis[i] = lis[j] + 1;
				ans = max(ans, lis[i]);
			}
		}
	}

	printf("%d", ans);

}

