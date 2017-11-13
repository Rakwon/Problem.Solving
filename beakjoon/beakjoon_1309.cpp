#include <cstdio>

int main(void){

	long long int n, k, ans, d[100010][3];
	scanf("%lld", &n);

	d[1][1] = d[1][2] = 1;
	d[2][1] = d[2][2] = 2;
	d[1][0] = 1,d[2][0] = 3;

	for(int i = 3; i<=n ;++i){
		d[i][1] = (d[i-1][2] + 1 + 2*d[i-2][0])%9901;
		d[i][2] = (d[i-1][1] + 1 + 2*d[i-2][0])%9901;
		d[i][0] = (d[i-1][0] + d[i][1])%9901;

	}

	ans = 0;
	for(int i = 1; i<=n; ++i)
		ans += (2*d[i][1])%9901;


	printf("%d", (ans + 1)%9901);

	return 0;
}

