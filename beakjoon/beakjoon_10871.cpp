#include <cstdio>

int main(void){

    int n, x, arr[10010];
    scanf("%d %d", &n, &x);
    for(int i = 0; i<n; scanf("%d", &arr[i++]));
    for(int i = 0; i<n; ++i)
        if( arr[i] < x )
            printf("%d ", arr[i]);
    return 0;
}
