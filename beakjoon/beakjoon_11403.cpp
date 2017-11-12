#include <cstdio>
#define INF 9999999

int main(void){

	int n;
	int map[101][101];
	scanf("%d", &n);

	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			for(int k = 0; k<n; ++k){
				if(map[j][i] == 1 && map[i][k] == 1)
					map[j][k] = 1;
			}
		}
	}

	for(int i = 0; i<n; ++i){
		for(int j = 0; j<n; ++j){
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}

