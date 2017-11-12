#include <cstdio>
#define INF 99999999

int min(int a, int b){
	return a > b ? b : a;
}
int main(void){

	int n, m, f, t, w;
	int map[101][101];
	scanf("%d %d\n", &n, &m);

	for(int i = 0; i<101; ++i){
		for(int j = 0; j<101; ++j)
			map[i][j] = INF;
		map[i][i] = 0;
	}

	for(int i = 0; i<m; ++i){
		scanf("%d %d %d", &f, &t, &w);
		map[f][t] = min(w, map[f][t]);
	}

	for(int k = 1; k<=n; ++k){
		for(int i = 1; i<=n; ++i){
			for(int j = 1; j<=n; ++j){
				if(map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for(int i = 1; i<=n; ++i){
		for(int j = 1; j<=n; ++j){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}

