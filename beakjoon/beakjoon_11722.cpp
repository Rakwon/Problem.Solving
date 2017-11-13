#include <cstdio>

int main(void){

	int n, arr[1001], lds[1001], ans =1;
	scanf("%d", &n);
	for(int i = 1; i<=n; ++i)
		scanf("%d", &arr[i]);

	for(int i = 1; i<=n; ++i){
		lds[i] = 1;
		for(int j = 1; j<i; ++j ){
			if(arr[i] < arr[j] && lds[i] < lds[j]+1){
				lds[i] = lds[j] + 1;
				ans = lds[i] > ans ? lds[i] : ans;
			}
		}
	}

	printf("%d", ans);
	return 0;

}

