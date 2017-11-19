#include <cstdio>

int min(int a, int b){
    return a>b?b:a;
}
int max(int a, int b){
    return a>b?a:b;
}

int main(void){

    int n;
    int a, b, c,
        aMin, bMin, cMin,
        aMax, bMax, cMax;

    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d %d %d", &a, &b, &c);
        if(i == 0){
            aMin = aMax = a;
            bMin = bMax = b;
            cMin = cMax = c;
        }
        else{
            int _a = min(aMin, bMin) +a;
            int _b = min(aMin, min(bMin, cMin)) + b;
            int _c = min(bMin, cMin) + c;
            aMin = _a, bMin = _b, cMin = _c;

            _a = max(aMax, bMax) + a;
            _b = max(aMax, max(bMax, cMax)) + b;
            _c = max(bMax, cMax) + c;
            aMax = _a, bMax = _b, cMax = _c;
        }
    }
    printf("%d %d",max(aMax, max(bMax, cMax)) ,min(aMin, min(bMin, cMin)));

    return 0;
}
