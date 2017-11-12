#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main(void){

	int n, h, block, mini = 500001;
	vector<int> low, high, ans;

	scanf("%d %d", &n, &h);

	low.assign(n/2, 0);
	high.assign(n/2, 0);
	ans.assign(200001, 0);

	for(int i = 0; i<n/2; scanf("%d %d", &low[i], &high[i]), ++i);

	sort(low.begin(), low.end());
	sort(high.begin(), high.end());

	vector<int>::iterator lit, hit;

	for(int i = 1; i <= h; ++i){
		lit = lower_bound(low.begin(), low.end(), i);
		hit = lower_bound(high.begin(), high.end(), h-i+1);
		block = ( low.end() - lit ) + ( high.end() - hit);
		++ans[block];
		if(block < mini)
			mini = block;
	}

	printf("%d %d",mini, ans[mini]);
}


