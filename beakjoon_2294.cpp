#include <cstdio>
#include <cstdlib>
#include <cstring>
#define INF 99999999

void clear(int buffer[]){

	for(int i = 0; i<10010; buffer[i++] = INF);
}
int min(int a, int b){
	return a>b?b:a;
}
int main(void){


	int n, total,coin[101], d[10010];

	clear(d);
	scanf("%d %d", &n, &total);
	d[0] = 0;

	for(int i = 1; i<=n; scanf("%d", &coin[i++]));
	for(int i = 1; i<=n; ++i){
		for(int j = coin[i]; j<=total; ++j){
			d[j] = min(d[j], d[j-coin[i]] + 1);

		}
	}
	if(d[total] == INF) printf("-1");
	else printf("%d", d[total]);


	return 0;
}

