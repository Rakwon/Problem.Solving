#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
using namespace std;

int d[101][101];
int max(int a ,int b){
	return a > b ? a : b;
}
void clear(){
	for(int i = 0; i<101; ++i)
		for(int j = 0; j<101; ++j)
			d[i][j] = -1;
}

int Knapsack(int i, int left, vector<int> &wt, vector<int> &v){

	if(i == 0 || left == 0) 
	    return 0;


	if(d[i][left] == -1){

		if( left - wt[i] >= 0)
			d[i][left] = max(Knapsack(i-1, left, wt, v), Knapsack(i-1, left-wt[i], wt, v) + v[i]);
		else
			d[i][left] = Knapsack(i-1, left, wt, v);
	}

	return d[i][left];
}
int main(void){

	int T, N, W;
	vector<int> wt,v;

	scanf("%d", &T);
	while(T--){

		scanf("%d %d", &N, &W);
		clear();
		wt.assign(N+1,0);
		v.assign(N+1, 0);
		for(int i = 1; i<=N; ++i) scanf("%d", &v[i]);
		for(int i = 1; i<=N; ++i) scanf("%d", &wt[i]);
		printf("%d\n", Knapsack(N, W, wt, v));
	}
	return 0;
}

