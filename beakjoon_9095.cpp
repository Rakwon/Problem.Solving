#include <cstdio>

int bottom_up(int n){

	int d[n+1];

	d[0] = d[1] = 1; d[2] = 2; d[3] = 4;
	for(int i = 4; i<=n; ++i)
		d[i] = d[i-1] + d[i-2] + d[i-3];

	return d[n];
}
int main(void){

	int a, n;
	scanf("%d", &n);
	for(int i = 0; i<n; ++i ){
		scanf("%d", &a);
		printf("%d\n", bottom_up(a));
	}


}

