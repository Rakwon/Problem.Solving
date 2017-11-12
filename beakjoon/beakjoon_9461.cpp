#include <cstdio>

int main(void){

	long long int t, n, p[101];
	p[1] = p[2] = p[3] = 1;
	p[4] = p[5] = 2;


	for(int i = 6; i<=100; ++i)
		p[i] = p[i-1] + p[i-5];

	scanf("%lld", &t);
	while(t--){
		scanf("%lld", &n);
		printf("%lld\n", p[n]);
	}

	return 0;
}

