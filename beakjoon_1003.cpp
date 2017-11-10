#include <cstdio>
#include <utility>
#include <iostream>
using namespace std;

typedef pair<int, int> P;
P numCount[41];

void bufferClear(){
	for(int i = 0; i<41; ++i)
		numCount[i].first = numCount[i].second = 0;
}
void fibonacci(int n){

	numCount[0].first = 1;
	numCount[0].second = 0;

	numCount[1].first = 0;
	numCount[1].second = 1;

	for(int i = 2; i<=n; ++i){
		numCount[i].first = numCount[i-1].first + numCount[i-2].first;
		numCount[i].second = numCount[i-1].second + numCount[i-2].second;
	}
};

int main(void){

	int t, n;
	scanf("%d", &t);

	while(t--){
		bufferClear();
		scanf("%d", &n);
		fibonacci(n);
		printf("%d %d\n", numCount[n].first, numCount[n].second);
	}
	return 0;
}

