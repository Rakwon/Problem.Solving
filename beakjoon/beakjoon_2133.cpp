#include <cstdio>
#include <cstring>
#include <cstdlib>
int main(void){

	long long int n, d[31];
	scanf("%lld", &n);

	memset(d, 0, sizeof(d));

	d[0] = 1;
	d[2] = 3;
	for(int i = 4; i<=n; i+=2){
		d[i] = d[i-2]*3;
		for(int j = 4; j<=i; j+=2)
			d[i] += d[i-j]*2;
	}
	printf("%lld", d[n]);

	return 0;
}

