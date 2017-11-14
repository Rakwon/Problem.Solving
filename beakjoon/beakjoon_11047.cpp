#include <cstdio>
int main(void){

	int n, k, A[10], ans = 0;
	scanf("%d %d", &n, &k);
	for(int i = 0; i<n; ++i) scanf("%d", &A[i]);

	for(int i = n-1; k && i>=0; --i){
		ans += k/A[i];
		k %=A[i];
	}

	printf("%d", ans);
	return 0;
}

