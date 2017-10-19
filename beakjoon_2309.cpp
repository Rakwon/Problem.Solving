#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int is_stop;
vector<int> tall = vector<int>(9);

void search(int, vector<int>);
int totalSum(vector<int>);
int printSet(vector<int>);

int main(void){

	vector<int> set;

	for(int i = 0; i<9; scanf("%d", &tall[i++]));
	sort(tall.begin(), tall.end());
	search(0, set);

	return 0 ;
}
int printSet(vector<int> set){
	for(int i = 0; i<7; ++i)
			printf("%d\n", tall[set[i]]);
}
int totalSum(vector<int> set){

	int sum = 0;
	for(int i = 0; i<7; sum += tall[set[i++]]);
	return sum;
}
void search(int now, vector<int> set){

	if(is_stop == 1)
		return ;

	if(now >= 9 || set.size() == 7){
		if(set.size() == 7 && totalSum(set) == 100){
			printSet(set);
			is_stop = 1;
		}
		return ;
	}

	set.push_back(now);
	for(int i = now+1; i<=9; ++i)
		search(i, set);
	set.pop_back();

}


