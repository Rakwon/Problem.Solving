#include <cstdio>

int isPrime(int a){

    if( a <= 1) return 0;
    if( a == 2) return 1;
    
    int prime = 1;
    for(int i = 2; i*i <= a; ++i){
        if(a % i == 0){
            prime = 0;
            break;
        }
    }

    return prime;
}
int main(void){

    int n, a, ans = 0;
    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        ans += isPrime(a);
    }
    printf("%d", ans);
    return 0;
}
