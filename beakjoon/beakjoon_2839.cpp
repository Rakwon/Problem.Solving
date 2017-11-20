#include <cstdio>
#define INF 99999999
int min(int a, int b){
    return a > b ? b : a;
}
int main(void){

    int n, ans = INF;
    scanf("%d", &n);

    for(int i = 0; i<=n/3; ++i){
        for(int j = 0; j<=n/5; ++j){
            int sum = i*3+j*5;
            if(sum > n) break;
            if( sum == n ){
                ans = min(ans, i + j);
            }
        }
    }
    if(ans == INF) printf("-1");
    else printf("%d", ans);
    return 0;
}
