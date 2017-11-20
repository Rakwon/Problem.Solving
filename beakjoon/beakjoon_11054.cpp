#include <cstdio>
#include <climits>

int arr[1001], lis[1001], lds[1001];

int max(int a, int b){
    return a > b ? a : b;
}
int main(void){

    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", &arr[i]);

    for(int i = 1; i<=n; ++i){
        lis[i] = 1;
        for(int j = 1; j<i; ++j){
            if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
        }
    }

    for(int i = n; i>=1; --i){
        lds[i] = 1;
        for(int j = n; j > i; --j){
            if(arr[i] > arr[j] && lds[i] < lds[j] + 1)
                lds[i] = lds[j] + 1;
                
        }
    }

    int ans = INT_MIN;
    for(int i = 1; i<=n; ++i)
        ans = max(ans, lis[i] + lds[i] - 1);
    
    printf("%d", ans);
    return 0;
}
