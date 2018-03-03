#include <cstdio>
#include <cmath>
#define MAXI 999999999

int min(int a, int b){
	return a > b ? b : a;
}
int main(void){
	
	int sum = 0, min = MAXI, from, to;
	scanf("%d %d", &from, &to);
	
	for(int i = from; i<=to; ++i){
		double sqr = (double)sqrt(i);
		if( ceil(sqr) == floor(sqr)){
			if(min == MAXI) min = i;
			sum += i;
		}
	}
	
	if(sum == 0)	printf("-1");
	else			printf("%d\n%d", sum, min);
	
	return 0;
}

