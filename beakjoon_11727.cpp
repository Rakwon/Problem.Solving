#include <cstdio>
#include <cstdlib>
#include <cstring>

long long int d[1001];
long long int top_down(int n){

 	if(n == 1) return 1;
	if(n == 2) return 3;

	if(d[n] == -1)
		d[n] = (top_down(n-1) + 2*top_down(n-2))%10007;

	return d[n]%10007;
}

long long int bottom_up(int n){

	d[1] = 1; d[2] = 3;
	for(int i = 3; i<=n; ++i)
		d[i] = (d[i-1] + d[i-2]*2) % 10007;

	return d[n]%10007;
}
int main(void){

	int n;

	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	printf("%lld", top_down(n));
	//printf("%lld", bottom_up(n));

	return 0;
}

