#include <cstdio>
#include <vector>
#include <climits>
#include <iostream>
using namespace std;

int d[501][501];
int min(int a, int b){
	return a < b ? a : b;
}
void clear(){
	for(int i = 0; i<501; ++i)
		for(int j = 0; j<501; ++j)
			d[i][j] = -1;
}

int MatrixChainning(vector<int> &arr, int s, int e){

	if(s+1 == e)
		return 0;

	if(d[s][e] == -1){
		int cnt;
		d[s][e] = INT_MAX;
		for(int i = s+1; i<e; ++i){
			cnt = 	MatrixChainning(arr, s, i) +
					MatrixChainning(arr, i, e) +
					arr[s]*arr[i]*arr[e];

			d[s][e] = min(d[s][e], cnt);
		}
	}

	return d[s][e];
}
int main(void){

	int T, N;
	vector<int> A;

	scanf("%d", &T);

	while(T--){
		scanf("%d", &N);
		A.assign(N+1, 0);
		clear();
		for(int i = 0; i<N; ++i)
			scanf("%d", &A[i]);

		printf("%d\n", MatrixChainning(A, 0, N-1));
	}


	return 0;
}

