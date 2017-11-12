
#include <cstdio>
#include <cstdlib>
#include <cstring>

int n, wine[10010], d[10010];
int max(int a , int b){
	return a > b ? a : b;
}


void bottom_up(){

	//경우의수 3가지
	// 1. 현재 와인을 먹지 않은경우
	// 2. 현재 와인을 먹고 이전것을 먹지 않은경우.
	// 3. 현재 와인과 이전와인을 먹은 경우.
	// 이 세가지중 최대값이 정답.

	for(int i = 3; i<=n; ++i)
		d[i] = max(d[i-1], max(wine[i] + wine[i-1] + d[i-3], wine[i] + d[i-2]));

	printf("%d", d[n]);

}
int func(int n){


	if(d[n] == -1){
		d[n] = max(func(n-1), max(wine[n] + wine[n-1] + func(n-3), wine[n] + func(n-2)));
	}
	return d[n];
}
void top_down(){
	printf("%d", func(n));
}

int main(void){

	memset(d, -1, sizeof(d));
	scanf("%d", &n);
	for(int i = 1; i<=n; ++i)
		scanf("%d", &wine[i]);

	d[0] = 0;
	d[1] = wine[1];
	d[2] = wine[1] + wine[2];

	//bottom_up();
	top_down();
	return 0;
}

