#include <cstdio>

int main(void){
	
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	
	for(int i = 0; i<=15*28*19; ++i){
		if( i%15 + 1 == a && i%28 +1 == b && i%19 + 1 == c){
			printf("%d", i+1);
			break;
		}
	}
	
	return 0;
}

