#include <cstdio>


int main(void){

	int n, m, f, t, k;
	int map[401][401];

	for(int i = 0; i<401; ++i) for(int j = 0; j<401; ++j) map[i][j] = 0;
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

	scanf("%d", &k);

	for(int i = 0; i<k; ++i){
		scanf("%d %d", &f, &t);
		if(map[f][t] == 1) printf("-1");
		else if( map[f][t] == 0 && map[t][f] == 0) printf("0");
		else printf("1");

		printf("\n");
	}

	return 0;
}

