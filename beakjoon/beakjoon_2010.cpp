#include <cstdio>

int main(void){

    int n, total = 0, a;
    
    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        total += (a -1);
    }

    printf("%d", total + 1);
    return 0;
}
