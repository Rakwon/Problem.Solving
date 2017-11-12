#include <cstdio>
#define INF 99999999


int min(int a, int b){
	return a > b ? b : a;
}
int main(void){

	int n, m, from, to;
	int map[101][101];
	scanf("%d %d", &n, &m);

	for(int i = 0; i<101; ++i){
		for(int j = 0; j<101; ++j)
			map[i][j] = INF;
	}

	for(int i = 0; i<m; ++i){
		scanf("%d %d", &from, &to);
		map[from][to] = map[to][from] = 1;
	}

	for(int k = 1; k<=n; ++k){
		for(int i = 1; i<=n; ++i){
			for(int j = 1; j<=n; ++j){
				if(map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	int mini = INF;
	int man = 1;
	for(int i = 1; i<=n; ++i){
		int temp = 0;
		for(int j = 1; j<=n; ++j){
			if(i != j)
				temp += map[i][j];
		}

		if(temp < mini){
			mini = temp;
			man = i;
		}
	}

	printf("%d", man);

	return 0;
}

