#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> num;

void printSet(vector<int> set){

	int len = set.size();
	for(int i = 0; i<len; ++i){
		printf("%d ", set[i]);
	}
	printf("\n");
}
void process(int index, vector<int> set){
	if(set.size() == 6){
			printSet(set);
			return ;
	}

	if(index >= num.size())
		return ;

	int len = num.size();
	for(int i = index; i<len; ++i){
		set.push_back(num[i]);
		process(i+1, set);
		set.pop_back();
	}
}
int main(void){

	int n;

	while(1){
		scanf("%d", &n);
		if(n == 0)
			break;
		else{

			num.assign(n, 0);
			for(int i = 0; i<n; scanf("%d", &num[i++]));
			sort(num.begin(), num.end());
			process(0, vector<int>());
			printf("\n");
		}
	}
	return 0;
}

