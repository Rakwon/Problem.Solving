
/*
 * 풀이
 * lower_bound - upper_bound
 * 
 */
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


long long N, M, maxi = 0;
vector<long long> numList;

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
	numList.assign(N, 0);

	for(long long i = 0; i<N; scanf("%lld\n", &numList[i++]));

	sort(numList.begin(), numList.end());
}
void process(){

	long long k;
	vector<long long >::iterator upp_it, low_it;

	scanf("%lld", &M);
	for(int i = 0; i<M; ++i){
		scanf("%lld", &k);
		low_it = lower_bound(numList.begin(), numList.end(), k);
		upp_it = upper_bound(numList.begin(), numList.end(), k);
		printf("%d ", (upp_it - numList.begin()) - (low_it - numList.begin()));

	}
}
long long max(long long a, long long b){
	return a > b ? a : b;
}

