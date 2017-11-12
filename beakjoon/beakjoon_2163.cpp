#include <cstdio>
#include <cstdlib>
#include <cstring>

int d[301][301];
#define INF 99999999
int min(int a, int b){
	return a > b ? b : a;
}
int divide(int n, int m){

	if(n == 1 && m == 1) return 0;

	if(d[n][m] == -1){
		int r1 = INF, r2 = INF;
		// 행으로 자르기
		for(int i = 1; n>1 && i<n; ++i)
			r1 = min(r1, divide(i, m) + divide(n-i, m) + 1);
		for(int i = 1; m>1 && i<m; ++i)
			r2 = min(r2, divide(n, i) + divide(n, m-i) + 1);

		d[n][m] = min(r1, r2);
	}

	return d[n][m];
	// 열로 자르기
}
int main(void){

	int n, m;
	memset(d, -1, sizeof(d));
	scanf("%d %d", &n, &m);
	printf("%d", divide(n, m));
	return 0;

}

