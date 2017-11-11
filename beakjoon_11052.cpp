#include <cstdio>
#include <cstdlib>
#include <cstring>

int d[10010];
int max(int a, int b){
	return a > b ? a : b;
}
int top_down(int val[], int l){

	if(l == 0) return 0;

	if(d[l] == -1){
		for(int i = 1; i<=l; ++i)
			d[l] = max(d[l], top_down(val, l-i) + val[i]);

	}
	return d[l];

};
int bottom_up(int val[], int n){

	d[0] = 0;

	for(int i = 1; i<=n; ++i){
		for(int j = 1; j<=i; ++j){
			 d[i] = max(d[i], d[i-j] + val[j]);
		}
	}

	return d[n];
}

int main(void){

	int n, val[10010];
	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for(int i = 1; i<=n; ++i)
		scanf("%d",&val[i]);

	//printf("%d", top_down(val, n));
	printf("%d", bottom_up(val, n));

	return 0;
}

