#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


long long int N, M;
vector<long long int> check;
long long int min(long long int, long long int);
int canCheck(long long int);

int main(void){

	long long int s = 1, e = 1000000000000000000, m;
	long long int ans = LLONG_MAX;

	scanf("%lld %lld\n", &N, &M);
	check.assign(N, 0);

	for(long long int i = 0 ; i<N;scanf("%lld", &check[i++]));


	while(s <= e){

		m = (s + e)/2;
		if(canCheck(m) == 1){
			ans = min(ans, m);
			e = m - 1;
		}
		else{
			s = m + 1;
		}
	}

	printf("%lld", ans);
	return 0;
}
long long int min(long long int a , long long int b){
	return a > b ? b : a;
}
int canCheck(long long int sec){

	long long int num = M;

	for(long long int i = 0; i<N; ++i){
		long long int a = sec/check[i];

		num -= a;
		if(num <= 0) break;
	}

	return num <= 0 ? 1 : 0;
}

