#include <cstdio>

int main(void){

	int n;
	scanf("%d", &n);
	
	
	// 100만인 경우 모든 자릿수가 자리의 합이 최대 63;
	// 따라서 n-63이하의 수로는 분해합으로 n을 만들 수가 없음.
	
	int k = n-63 < 0 ? 0 : n-63;

	for(k = 1; k < n; ++k){

		int ans = k;
		int j = k;

		while(j){
			ans += j%10;
			j /= 10;
		}

		if(ans == n){
			printf("%d", k);
			return 0;
		}
	}
	printf("0");

	return 0;
}

