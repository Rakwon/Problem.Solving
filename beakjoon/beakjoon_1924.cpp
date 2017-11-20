#include <cstdio>

int day[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(void){


    int a, b, ans = 0;
    scanf("%d %d", &a, &b);
    
    for(int i = 1; i<a; ++i) ans += day[i];
    ans += b;

    switch(ans%7){
        case 0 : printf("SUN");
        break;
        case 1 : printf("MON");
        break;
        case 2 : printf("TUE");
        break;
        case 3 : printf("WED");
        break;
        case 4 : printf("THU");
        break;
        case 5 : printf("FRI");
        break;
        case 6 : printf("SAT");
        break;
    };

    return 0;

}
