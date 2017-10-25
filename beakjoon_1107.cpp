#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int block_button[10];
int approxi = 100000000;

int max(int a, int b){
	return a > b ? a : b;
}
int min(int a, int b){
	return a > b ? b : a;
}
int abs(int a){
	return a < 0 ? (-1)*a : a;
}
int getDigit(int b){


	int a = 1;
	b/=10;
	while(b){
		++a;
		b/=10;
	}

	return a;
}
void getApproxi(int cur, int target, int digit){

	if(digit <= 0)
		return ;

	for(int i = 0; i<=9; ++i){
		if(!block_button[i]){

			int next = cur*10 + i;
			int dif = abs(next - target) + getDigit(next);
			approxi = min(approxi, dif);
			getApproxi(next, target, digit-1);
		}
	}
}
void process(int n){

	// 2 단계로 나눔
	// 	1. +, - 로만 갈 떄 버튼 클릭수
	// 	2. 숫자로 채널 이동 후 +, - 버튼 클릭 수.

	int digit = getDigit(n);
	getApproxi(0, n, digit+1);
	int no_num_button = abs(n - 100);
	printf("%d", min(no_num_button, approxi));

}
int main(void){

	int n, k, a;
	scanf("%d %d", &n, &k);
	for(int i = 0; i<k; ++i){
		scanf("%d", &a);
		block_button[a] = 1;
	}

	process(n);

	return 0;
}

