#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

int map[501][501], d[501][501];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int isInside(int y, int x, int N, int M){
    return ( (y >= 1 && y <= N) && (x >=1 && x <= M) );
}

int process(int y, int x, int N, int M){

    if(y == 1 && x == 1) 
        return 1;

    if(d[y][x] == -1){
        d[y][x] = 0;
        for(int i = 0 ; i < 4 ; ++i){
            int _x = x + dx[i];
            int _y = y + dy[i];

            if(isInside(_y, _x, N, M) && map[y][x] < map[_y][_x])
                d[y][x] += process(_y, _x, N, M);
        }
    }
    
    return d[y][x];
    
}
int main(void){

    int N, M;

    scanf("%d %d", &N, &M);
    memset(d, -1, sizeof(d));
    for(int i = 1; i<=N; ++i){
        for(int j = 1; j<=M; ++j){
            scanf("%d", &map[i][j]);
        }
    }
   
    printf("%d", process(N, M, N, M));
    return 0;
}
