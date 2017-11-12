#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> house;

void input();
void process();
int install(int);
int max(int ,int);

int main(void){

	input();
	process();
	return 0;

}

void input(){
	scanf("%d %d", &N, &M);
	house.assign(N, 0);

	for(int i = 0 ; i < N; scanf("%d", &house[i++]));
	sort(house.begin(),house.end());

}
void process(){

	int s = 1, e = house[N-1] - house[0];
	int m, ans = 0;
	while( s <= e ){

		m = ( s + e )/2;

		//m으로 만들 수 공유기를 놓을 수 있으
		if(install(m) == 1){
			s = m+1;
			ans = max(ans, m);
		}
		else{
			e = m-1;
		}
	}

	printf("%d", ans);
}
int install(int interval){

	int num = M - 1;
	int index = 0;
	for(int i = 1; num > 0 && i<N; ++i){
		// 거리가 interval 이상이면 놓는다.
		if(house[i] - house[index] >= interval){
			index = i;
			--num;
		}
	}

	return num == 0 ? 1 : 0;
}
int max(int a,int b){
	return a > b ? a : b;
}

