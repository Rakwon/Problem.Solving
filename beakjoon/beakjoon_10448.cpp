// sub set 문제
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){
	return a > b ? a : b;
};
int sum(int n){
	return (n*(n+1))/2;
};
int search(int index, vector<int>set, int ans){

	if(set.size() >= 3){
		int _sum = 0;
		_sum = sum(set[0]) + sum(set[1]) + sum(set[2]);
		return _sum == ans;
	}

	int result = 0;
	for(int i = index; sum(i) < ans; ++i){
		set.push_back(i);
		result = max(result, search(i, set, ans));
		set.pop_back();
	}

	return result;
};
int main(void){

	int n, k;
	vector<int> set;
	scanf("%d", &n);

	for(int i = 0; i<n; ++i){
		set.clear();
		scanf("%d", &k);
		printf("%d\n", search(1,set,k));
	}

	return 0;
}


