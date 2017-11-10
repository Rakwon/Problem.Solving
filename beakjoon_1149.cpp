#include <cstdio>

int map[1001][3];
int t[1001][3];

int min(int a, int b){
	return a > b ? b : a;
}
void bottom_up(){

	int n, r, g, b;
	scanf("%d", &n);

	for(int i = 0; i<n; ++i)
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);

	t[0][0] = map[0][0];
	t[0][1] = map[0][1];
	t[0][2] = map[0][2];

	for(int i = 1; i<n; ++i){
		t[i][0] = min(t[i-1][1], t[i-1][2]) + map[i][0];
		t[i][1] = min(t[i-1][0], t[i-1][2]) + map[i][1];
		t[i][2] = min(t[i-1][0], t[i-1][1]) + map[i][2];
	}

	printf("%d", min(t[n-1][0], min(t[n-1][1], t[n-1][2])));
}
int func(int n, int c){

	if( n == 0 )
		return t[n][c] = map[n][c];

	int ret;
	if( t[n][c] != 0 )
		ret = t[n][c];

	else{
		if(c == 0)
			ret = min(func(n-1, 1), func(n-1, 2)) + map[n][c];
		if(c == 1)
			ret = min(func(n-1, 0), func(n-1, 2)) + map[n][c];
		if(c == 2)
			ret = min(func(n-1, 0), func(n-1, 1)) + map[n][c];
	}
	return ret;
}
void top_down(){

	int n, r, g, b;
	scanf("%d", &n);

	for(int i = 0; i<n; ++i)
		scanf("%d %d %d", &map[i][0], &map[i][1], &map[i][2]);

	t[0][0] = map[0][0];
	t[0][1] = map[0][1];
	t[0][2] = map[0][2];

	printf("%d", min(func(n-1, 0), min(func(n-1,1), func(n-1, 2))));
}

int main(void){

	//bottom_up();
	top_down();
	return 0;
}

