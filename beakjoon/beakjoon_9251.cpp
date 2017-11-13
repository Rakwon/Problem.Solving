#include <cstdio>
#include <cstdlib>
#include <cstring>

int max(int a, int b){
	return a > b ? a : b;
}

int main(void){

	char a[1002], b[1002];
	int d[1002][1002];

	int aLen, bLen;
	a[0] = b[0] = '/0';
	scanf("%s %s", &a[1], &b[1]);

	aLen = strlen(a)-1;
	bLen = strlen(b)-1;

	for(int i = 0; i<=1001; ++i)
		d[i][0] = d[0][i] = 0;

	for(int i = 1; i<=aLen; ++i){
		for(int j = 1; j<=bLen; ++j){
			if(a[i] == b[j]) d[i][j] = d[i-1][j-1] + 1;
			if(a[i] != b[j]) d[i][j] = max(d[i-1][j], d[i][j-1]);
		}
	}

	printf("%d", d[aLen][bLen]);

	return 0;
}

