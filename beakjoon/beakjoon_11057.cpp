#include <cstdio>
#include <cstring>
#include <cstdlib>
long long int n, d[1010][10];
int main(void){
    
	scanf("%lld", &n);
	for(int i = 0; i<10; d[1][i++] = 1);
	for(int i = 2; i<=n; ++i){
		for(int j = 0; j<10; ++j){
			for(int k = 0; k<=j; ++k){
				d[i][j] += d[i-1][k]%10007;
			}
		}
	}

	long long int ans = 0;
	for(int i = 0; i<10; ans += d[n][i++]%10007);
	printf("%lld", ans%10007);
}

