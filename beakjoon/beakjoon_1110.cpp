#include <cstdio>

int main(void){
    

    int n, cur = 0,cycle = 0;
    scanf("%d", &n);
    
    cur = n;
    
    do{
        if( n < 10 )
            n = n*10 +n;
        else{
            int left = n/10;
            int right = n%10;
            int sum_right = (left + right)%10;
            n = right*10 + sum_right;
        }
        ++cycle;
    }while(cur != n);

    printf("%d", cycle);
    return 0;

}
