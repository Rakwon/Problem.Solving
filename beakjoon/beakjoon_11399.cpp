#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(void){

	int n, ans[1001], ret = 0;;
	scanf("%d", &n);

	vector<int> time(n+1);
	for(int i = 0; i<n; ++i) scanf("%d", &time[i]);
	sort(time.begin(), time.end());

	ans[0] = time[0];
	for(int i = 1; i<time.size(); ++i){
		ans[i] = ans[i-1] + time[i];
		ret += ans[i];
	}

	printf("%d", ret);
	return 0;
}

