#include <cstdio>

int max(int a, int b){
	return a > b ? a : b;
}
int main(void){

	int n;
	int map[501][501];
	int d[501][501];
	scanf("%d", &n);

	for(int i = 1; i<=n; ++i){
		for(int j = 1; j<=i; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	d[1][1] = map[1][1];

	for(int i = 2; i<= n; ++i){
		for(int j = 1; j<=i; ++j){
			if(j == 1)
				d[i][j] = d[i-1][j] + map[i][j];
			else if(j == i)
				d[i][j] = d[i-1][j-1] + map[i][j];
			else
				d[i][j] = max(d[i-1][j], d[i-1][j-1]) + map[i][j];
		}
	}

	int ans = -1;
	for(int i = 1; i<=n; ans = max(ans, d[n][i++]));
	printf("%d", ans);
	return 0;

}

