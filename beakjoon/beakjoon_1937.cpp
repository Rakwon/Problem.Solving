#include <cstdio>
#include <cstdlib>
#include <cstring>

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int max(int a, int b){
	return a > b ? a : b;
}
int isInside(int yy, int xx, int n){
	return xx >=1 && xx <=n && yy>=1 && yy<=n;
}
int search(int y, int x, int n, int visited[501][501], int map[501][501], int d[501][501]){

	if(visited[y][x] == 1)
		return d[y][x];

	visited[y][x] = 1;

	for(int i = 0; i<4; ++i){
		int xx = x + dx[i], yy = y + dy[i];
		if(isInside(yy, xx, n) && map[yy][xx] > map[y][x])
			d[y][x] = max(d[y][x], search(yy, xx,n, visited, map, d) + 1);

	}
	return d[y][x];
}

void process(int n, int map[501][501]){

	int visited[501][501], ans = 1;
	int d[501][501];

	for(int i = 1; i<=n; ++i){
		for(int j = 1; j<=n; ++j){
			visited[i][j] = 0;
			d[i][j] = 1;
		}
	}
	for(int i = 1; i<=n; ++i)
		for(int j = 1; j<=n; ++j)
			ans = max(ans, search(i, j, n, visited, map, d));

	printf("%d", ans);
}
int main(void){

	int n, map[501][501];
	scanf("%d", &n);

	for(int i = 1; i<=n; ++i)
		for(int j = 1; j<=n; ++j)
			scanf("%d", &map[i][j]);

	process(n, map);
	return 0;
}

