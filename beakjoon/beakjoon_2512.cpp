#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


long long N, M, maxi = 0;
vector<long long> money;

void input();
void process();
long long max(long long , long long);
int cal(long long);

int main(void){

	input();
	process();
	return 0;
}
void input(){

	scanf("%lld", &N);
	money.assign(N, 0);

	for(long long i = 0; i<N; ++i){
		scanf("%lld\n", &money[i]);
		maxi = max(maxi, money[i]);
	}

	scanf("%lld", &M);
}
void process(){

	long long  exp, ans = 0, sum = 0, s = 0, e = maxi;

	while(s <= e){

		exp = (s + e)/2;
		if(cal(exp) == 1){
			ans = max(ans, exp);
			s = exp + 1;
		}
		else{
			e = exp -1;
		}
	}

	printf("%d", ans);
}
long long max(long long a, long long b){
	return a > b ? a : b;
}
int cal(long long exp){

	long long sum = 0;
	for(long long i = 0; i<N; ++i){
		if(money[i] < exp) sum += money[i];
		else sum += exp;
	}

	return M >= sum ? 1 : 0;
}

