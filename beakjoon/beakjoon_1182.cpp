#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int N, S, ans;
vector<int> num;

void input(){
	scanf("%d %d", &N, &S);
	num.assign(N, 0);
	for(int i = 0; i<N; scanf("%d", &num[i++]));
}
int checkSum(vector<int> set){
	int len = set.size();
	int sum = 0;
	for(int i = 0; i<len; sum+= set[i++]);

	return sum == S ? 1 : 0;
}
void process(int index, vector<int> set){

	int len = num.size();
	for(int i = index; i< len; ++i){
		set.push_back(num[i]);
		if(checkSum(set) == 1) ++ans;
		process(i+1, set);
		set.pop_back();
	}
}
int main(void){

	vector<int> set;
	input();
	process(0, set);
	printf("%d", ans);
	return 0;

}

