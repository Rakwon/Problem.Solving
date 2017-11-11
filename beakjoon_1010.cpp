#include <cstdio>

int main(void){

	int t, a, b;
	int c[31][31];

	for(int i = 0; i<31; c[i][0] = c[i][i] = 1, ++i);

	for(int i = 2; i<31; ++i)
		for(int j = 1; j<i; ++j)
				c[i][j] = c[i-1][j] + c[i-1][j-1];

	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &a, &b);
		printf("%d\n", c[b][a]);
	}

	return 0;
}

