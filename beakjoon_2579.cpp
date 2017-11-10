#include <cstdio>

int stair[301];
int d[301];
void clear(){
	for(int i = 0; i<301; d[i++] = -1);
}
int max(int a, int b){
	return a > b ? a : b;
}
int search(int n){

	if( n == 1 ) return stair[1];
	if( n == 2 ) return stair[2] + stair[1];
	if( n == 3 ) return max(stair[3] + stair[2], stair[1] + stair[3]);

	if(d[n] == -1){
		d[n] = max(search(n-3) + stair[n-1] + stair[n], search(n-2) + stair[n]);
	}
	return d[n];
}
int main(void){

	int n;
	clear();
	scanf("%d", &n);
	for(int i =1; i<=n; ++i)
		scanf("%d", &stair[i]);

	printf("%d", search(n));
	return 0;
}

