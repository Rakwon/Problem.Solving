#include <cstdio>
#include <cstdlib>
#include <cstring>
long long int map[101][101], d[101][101];

long long int isInside(long long int y, long long int x, long long int n){
    return ( (y >= 1 && y <= n) && (x >= 1 && x <= n) );
};
long long int process(long long int y, long long int x, long long int n){

    if(y == n && x == n)
        return d[y][x] = 1;

    if(d[y][x] == -1){
        d[y][x] = 0;
        long long int _y = y + map[y][x];
        long long int _x = x + map[y][x];
        if( isInside(_y, x, n) ) d[y][x] += process(_y, x, n);
        if( isInside(y, _x, n) ) d[y][x] += process(y, _x, n);

    }
    
    return d[y][x];
}
int main(void){

    long long int n;

    memset(d, -1, sizeof(d));
    scanf("%lld", &n);
    for(long long int i = 1; i<=n; ++i){
        for(long long int j = 1; j<=n; ++j){
            scanf("%lld", &map[i][j]);
        }   
    } 

    printf("%lld", process(1, 1, n));
    return 0;
}
