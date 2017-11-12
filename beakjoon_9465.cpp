#include <cstdio>
#include <cstdlib>
#include <cstring>

int board[3][100010], d[3][100010];
int max(int a, int b){
	return a>b?a:b;
}
void buffer_clear(){

	for(int i = 1; i<=2; ++i){
		for(int j = 1; j<=100010; ++j)
			d[i][j] = 0;
	}
}
int ch(int a){
	if(a == 1) return 2;
	else return 1;
}
int top_down(int u, int i){

	if(i == 1)
		return board[u][i];
	if(i == 2)
		return u == 1 ? board[2][1] + board[1][2] : board[1][1] + board[2][2];

	if(d[u][i] == -1)
		d[u][i]= max(top_down(ch(u), i-1), max(top_down(1, i-2), top_down(2, i-2))) + board[u][i];

	return d[u][i];
}
int bottom_up(int n){

	d[1][1] = board[1][1];
	d[2][1] = board[2][1];

	d[1][2] = d[2][1] + board[1][2];
	d[2][2] = d[1][1] + board[2][2];

	for(int i = 3; i<=n; ++i){
		d[1][i] = max(d[2][i-1], max(d[1][i-2], d[2][i-2])) + board[1][i];
		d[2][i] = max(d[1][i-1], max(d[1][i-2], d[2][i-2])) + board[2][i];
	}

	return max(d[1][n], d[2][n]);
}
int main(void){

	int t, n;

	scanf("%d", &t);
	while(t--){

		scanf("%d", &n);

		for(int i = 1; i<=2; ++i){
			for(int j = 1; j<=n; ++j){
				scanf("%d", &board[i][j]);
			}
		}

		//memset(d, 0, sizeof(d));
		//printf("%d", bottom_up(n));

		memset(d, -1, sizeof(d));
		printf("%d\n", max(top_down(1, n), top_down(2, n)));
	}
	return 0;
}

