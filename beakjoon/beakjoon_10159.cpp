#include <cstdio>
#define INF 99999999

int main(void){

	int n, m, f, t;
	int map[101][101];

	scanf("%d %d", &n, &m);

	for(int i = 1; i<=n; ++i) for(int j = 1; j<=n; ++j) map[i][j] = INF;

	for(int i = 0; i<m; ++i){
		scanf("%d %d", &f, &t);
		map[f][t] = 1;

	}


	for(int k = 1; k<=n; ++k){
		for(int i = 1; i<=n; ++i){
			for(int j = 1; j<=n; ++j){
				if(map[i][k] == 1 && map[k][j] == 1)
					map[i][j] = 1;
			}
		}
	}


	for(int i = 1; i<=n; ++i){
		for(int j = 1; j<=n; ++j){
			if(map[i][j] == 1)
				map[j][i] = 1;
		}
	}


	for(int i = 1; i<=n; ++i){
		int ans = 0;
		for(int j = 1; j<=n; ++j){
			if(i != j && map[i][j] == INF)
				++ans;
		}
		printf("%d\n", ans);
	}

	return 0;
}

