/*
 * 
 * 풀이
 * 
 * 정답이 가질 수 이는 높이는  0 ~ 랜선 하나의 최댓값.
 * 여기서 높이를 절반씩 줄여가면서 해당높이 일때의 자른 랜선의 갯수를 센다.
 * 자른 랜선의 갯수가 모자라면 자르는 높이를 낮추고
 * 자른 랜선의 갯수가 남으면 자르는 높이를 높인다.
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

long long  n, m, maxi = 0;
vector<long long > line;

long long  max(long long , long long );
void input();
void process();
long long  slice(long long);

int main(void){


	input();
	process();
	return 0;
}
long long  max(long long  a, long long  b){

	return a > b ? a :b;
}
void input(){

	scanf("%lld %lld", &n, &m);
	line.assign(n, 0);

	for(long long  i = 0; i<n; scanf("%lld", &line[i]), maxi = max(maxi, line[i]), ++i);

}
void process(){

	long long  height, s = 0, e = maxi;
	long long  sum;
	long long  ans = 0;

	while( s < e ){

		height = (s + e)/2 + ( s + e )%2;
		sum = slice(height);

		if( sum < m )
			e = height;
		else{
			ans = max(ans, height);
			s = height + 1;
		}
	}
	printf("%d", ans);
}
long long  slice(long long  height){

	long long  num = 0;
	for(long long  i = 0; i<n; ++i){
		num += (line[i]/height);
	}

	return num;
}

