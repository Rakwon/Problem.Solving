#include <cstdio>
#include <cstdlib>

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

    int t, a, b;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &b);
        if(a > b)
            swap(&a, &b);
        printf("%d\n", a*b/gcd(a,b));
    }
    return 0;
}
