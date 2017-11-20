#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void){

    int n, arr[1001];
    vector<int> lis;

    
    scanf("%d", &n);
    for(int i = 1; i<=n; ++i)
       scanf("%d", &arr[i]);
    lis.push_back(arr[1]);

    for(int i = 2; i<=n; ++i){
        if( arr[i] > lis[lis.size()-1] )
            lis.push_back(arr[i]);
        else{
            vector<int>::iterator it = lower_bound(lis.begin(), lis.end(), arr[i]);
            *it = arr[i];
        }
    }

    //for(int i = 0; i< lis.size(); ++i) printf("%d ", lis[i]);
    printf("%d", lis.size());
    return 0;
}
