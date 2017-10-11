#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
long long n, m;
vector<long long> log;

void input();
void process();
long long slice(long long, long long);
int main(void){

	input();
	process();
	return 0;

}
void input(){

	scanf("%lld %lld", &n, &m);
	log.assign(n, 0);

	for(long long  i = 0; i < n; scanf("\n%lld", &log[i++]));
	sort(log.begin(), log.end());
}

void process(){

	long long s = 0;
	long long e = log[n-1];
	long long height;
	long long sum = 0;
	vector<long long>:: iterator it;

	while(s < e){
 		height = (s + e)/2 + (s + e)%2;
		it = lower_bound(log.begin(), log.end(), height);
 		sum = slice((long long)(it - log.begin()), height);

		if(sum == m){
			printf("%lld", height);
			return ;
		}
		else if( sum < m ){
			e = height - 1;
		}
		else
			s = height;
	}

	printf("%d", s);
}

long long  slice(long long startIndex, long long height){

	long long sum = 0;
	for(long long  i = startIndex ;i < n; sum += (log[i++] - height));

	return sum;
}

