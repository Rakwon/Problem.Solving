#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cstring>

int getMiniStick(int stick[]){

    int length = 1, i;
    for(i = 1; i <= 64; ++i)
        if(stick[i] != 0) 
            break;
    
    return i;
}
int getSum(int stick[]){
    int ret = 0;

    for(int i = 1; i<=64; ++i)
        if(stick[i])
            ret += (i*stick[i]);
    
    return ret;
}
int main(void){

    int stick[65], ans = 0, n;
    memset(stick, 0 , sizeof(stick));
    stick[64] = 1;

    scanf("%d", &n);

    if(n == 64)
        ans = 1; 
    else{
         while(1){

            int miniStick = getMiniStick(stick);
            --stick[miniStick];
            int half = miniStick/2;
            ++stick[half];

            int total_sum = getSum(stick);

            if(total_sum == n)
                break;
            else if(total_sum < n )
                ++stick[half];
                
        }
        for(int i = 1; i<=64; ans += stick[i++]);
    }
    
    
    printf("%d", ans);
    return 0;
}
