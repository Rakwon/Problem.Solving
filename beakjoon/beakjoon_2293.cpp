#include <cstdio>
#include <cstdlib>
#include <cstring>


int main(void){

	int n, sum, coin[101], d[10001];

	memset(d, 0, sizeof(d));
	scanf("%d %d", &n, &sum);
	for(int i = 1; i<=n; scanf("%d", &coin[i++]));

	d[0] = 1;

	for(int i = 1; i<=n; ++i){
		for(int j = coin[i]; j<=sum; ++j){
			d[j] += d[j-coin[i]];
		}
	}


	printf("%d", d[sum]);
	return 0;
}

