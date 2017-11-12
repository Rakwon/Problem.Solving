#include <cstdio>
#include <cstdlib>
#include <cstring>
int cal(int partial_sum[301][301], int fy, int fx, int ty, int tx){

	int ans = 0;
	for(int i = fy; i<= ty; ++i)
		ans += partial_sum[i][tx] - partial_sum[i][fx-1];

	return ans;
}
int main(void){

	int k, n, m, map[301][301], partial_sum[301][301];
	int fx, fy, tx, ty;

	memset(partial_sum, 0, sizeof(partial_sum));
	scanf("%d %d", &n, &m);

	for(int i = 1; i<=n; ++i){
		for(int j =1 ;j<=m; ++j){
			scanf("%d", &map[i][j]);
		}
	}

	for(int i = 1; i<=n; ++i){
		int sum = 0;
		for(int j =1 ;j<=m; ++j){
			sum += map[i][j];
			partial_sum[i][j] = sum;
		}
	}

	scanf("%d", &k);
	for(int i = 0; i<k; ++i){
		scanf("%d %d %d %d", &fy, &fx, &ty, &tx);
		printf("%d\n", cal(partial_sum, fy, fx, ty, tx));
	}
	return 0;
}

