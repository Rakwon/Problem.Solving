#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MOD 1000000000
int d[201][201];

int process(int n, int k, int sum){

    if(k == 0){
        if(sum == 0) return 1;
        return 0;
    }

    if(d[k][sum] == -1){
        d[k][sum] = 0;
        for(int i = n; i>=0; --i){
            if(sum - i >= 0)
                d[k][sum] = (d[k][sum] + process(n, k-1, sum-i))%MOD;
        }
    }
    
    return d[k][sum];
}
int main(void){

    int n, k;
    memset(d, -1, sizeof(d));
    scanf("%d %d", &n, &k);
    printf("%d", process(n, k, n));
    return 0;
}
