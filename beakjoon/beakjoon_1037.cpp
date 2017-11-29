#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){

    int n, a;
    vector<int> divisor;

    scanf("%d", &n);
    for(int i = 0; i<n; ++i){
        scanf("%d", &a);
        divisor.push_back(a);
    }

    sort(divisor.begin(), divisor.end());
    printf("%d", divisor[0]*divisor[divisor.size()-1]);
    
    return 0;
}
