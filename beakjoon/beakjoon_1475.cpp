#include <cstdio>
#include <climits>

int num[10];
int max(int a, int b){
    return a > b ? a :b ;
}
int main(void){

    int n, ans = INT_MIN;
    scanf("%d", &n);
    while(n){
        int _num = n%10;
        n/=10;
        ++num[_num];
    }

    for(int i = 0; i<10; ++i){
        if(i == 6 || i == 9) continue;
        ans = max(ans, num[i]);
    }

    int left = num[6] + num[9];
    printf("%d", max(ans, left/2 + left%2));
    return 0;
}
