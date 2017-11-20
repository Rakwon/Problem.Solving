#include <cstdio>

#define MOD 10007
int main(void){

    //nCn = 1, nC1 = 1
    //nCr = n-1Cr + n-1Cr-1;

    int C[1001][1001], n, r;

    for(int i = 0; i < 1001; ++i)
        C[i][0] = C[i][i] = 1;

    for(int i = 2; i<1001; ++i){
        for(int j = 1; j<i; ++j){
            C[i][j] = (C[i-1][j] + C[i-1][j-1])%MOD;
        }
    }

    scanf("%d %d", &n, &r);
    printf("%d", C[n][r]);

    return 0;
}
