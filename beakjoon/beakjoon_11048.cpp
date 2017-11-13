#include <cstdio>

int max(int a, int b){
	return a > b ? a : b;
}
int main(void){

	int n, m, map[1010][1010], d[1010][1010];
	scanf("%d %d", &n, &m);

	for(int i = 1; i<=n; ++i){
		for(int j =1; j<=m; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	d[1][1] = map[1][1];
	for(int i = 2; i<=m; ++i){
		d[1][i] = d[1][i-1] + map[1][i];
	}

	for(int i = 2; i<=n; ++i){
		for(int j = 1; j<=m; ++j){
			if(j == 1) 	d[i][j] = d[i-1][j] + map[i][j];
			else 		d[i][j] = max(d[i-1][j-1], max(d[i][j-1], d[i-1][j])) + map[i][j];
		}
	}

	printf("%d", d[n][m]);

}

