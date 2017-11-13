#include <cstdio>

void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
int gcd(int a, int b){

	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(void){

	int a ,b, c;
	scanf("%d %d", &a, &b);
	if(a < b ) swap(&a, &b);
	c = gcd(a,b);
	printf("%d\n%d", c, a*b/c);
}

