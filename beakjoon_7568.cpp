#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct _body{
	int tall;
	int weight;
}BODY;

int N;
vector<BODY> man;
vector<vector<int> > lessThan;

void input(){
	scanf("%d", &N);
	man.assign(N, (BODY){0, 0});
	lessThan.assign(N, vector<int>());
	for(int i = 0; i<N; scanf("%d %d", &man[i].weight, &man[i].tall), ++i);
}
void process(){

	vector<int> p = vector<int>(N, 0);
	//나보다 덩치가 작은 사람의 수 계산
	for(int i = 0; i<N; ++i){
		for(int j = 0; j< N; ++j){
			if(i == j) continue;
			if(man[i].weight < man[j].weight && man[i].tall < man[j].tall){
				lessThan[i].push_back(j);
			}
		}
	}

	for(int i= 0; i<N; ++i)
		printf("%d ", lessThan[i].size()+1);

}

int main(void){

	input();
	process();
	return 0;
}

