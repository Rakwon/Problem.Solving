#include <cstdio>


int main(void){

	int n, m, f, t, k;
	int map[501][501];

	for(int i = 0; i<501; ++i){
		for(int j = 0; j<501; ++j){
			if(i == j) map[i][j] = 1;
			else map[i][j] = 0;
		}
	}
	scanf("%d %d", &n, &m);

	for(int i = 0; i<m; ++i){
		scanf("%d %d", &f, &t);
		map[f][t] = 1;
	}

	for(int k = 1; k<=n; ++k)
		for(int i = 0; i<=n; ++i)
			for(int j = 0; j<=n; ++j)
				if(map[i][k] && map[k][j])
					map[i][j] = 1;

	int ans = 0;

	for(int i = 1; i<=n; ++i){
		int check = 1;
		for(int j = 1; j<=n; ++j){
			if(map[i][j] == 0 && map[j][i] == 0){
				check = 0;
				break;
			}
		}
		if(check)
			++ans;
	}

	printf("%d", ans);
	return 0;
}

