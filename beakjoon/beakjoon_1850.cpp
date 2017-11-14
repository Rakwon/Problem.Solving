#include <cstdio>

void swap(long long int *a, long long int *b){
	long long int t = *a;
	*a = *b;
	*b = t;
}
long long int gcd(long long int a, long long int b){

    while(b){
    	long long int t = a;
        a = b;
        b = t%b;
    }
    return a;
}
int main(void){

	long long int a ,b ;
	scanf("%lld %lld", &a, &b);
	if(a < b ) swap(&a, &b);
	long long int left = gcd(a, b);

	while(left--)
		printf("1");

	return 0;
}

