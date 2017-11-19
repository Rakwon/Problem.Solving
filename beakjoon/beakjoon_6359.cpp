#include <cstdio>
#include <cstdlib>
#include <cstring>


int room[101], d[101], t, n, total;    
int main(void){

    for(int i = 2; i<=100; ++i){
        for(int j = 1; j*i <= 100; ++j)
            room[i*j]^=1;
    }

    for(int i = 1; i<=100; ++i){
        if(room[i] == 0)
            ++total;

        d[i] = total;
    }
   
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        printf("%d\n", d[n]);
    }

    return 0;

}
