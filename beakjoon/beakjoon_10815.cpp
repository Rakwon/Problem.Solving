#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> numList, checkElement;

void input();
void process();
int main(void){


	input();
	process();
	return 0;
}
void input(){

	scanf("\n%d", &n);
	numList.assign(n, 0);
	checkElement.assign(n,0);

	for(int i = 0; i<n; scanf("\n%d", &numList[i++]));

	scanf("\n%d", &m);

}
void process(){

	sort(numList.begin(), numList.end());

	int target, s, e, success;

	for(int i = 0; i<m; ++i){

		scanf("\n%d", &target);
		s = 0, e = n-1;
		success = 0;

		while(s <= e){

			int mid = (s+e)/2;
			if(target == numList[mid]){
				success = 1;
				break;
			}
			else if( target > numList[mid])		s = mid +1;
			else if( target < numList[mid])		e = mid -1;
		}

		printf("%d ", success);
	}


}

