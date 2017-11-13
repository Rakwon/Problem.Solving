#include <cstdio>

#define INF 99999999

int min(int a, int b){
	return a > b ? b : a;
}
int main(void){

	int n, d[100010];
	scanf("%d", &n);

	for(int i = 0 ; i<100010; ++i) d[i] = INF;
	d[0] = 0,d[1] = 1;

	for(int i = 2; i<=n; ++i)
		for(int j = 1; j*j <= i; ++j)
			d[i] = min(d[i], d[i-(j*j)] + 1);

	printf("%d", d[n]);

	return 0;
}

