#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

typedef struct _node{
	int num;
	int pri;
}NODE;

int exist(vector<NODE> q){

	int a = q[0].pri;
	int len = q.size();

	for(int i = 1; i<len; ++i){
		if(q[i].pri > q[0].pri)
			return 1;
	}

	return 0;
}
int search(vector<NODE> q, int m){

	int pri = 1;

	while(1){
		if(exist(q)){
			q.push_back(q[0]);
			q.erase(q.begin());
		}
		else if( q[0].num != m ){
			q.erase(q.begin());
			++pri;
		}
		else
			break;
	}

	return pri;
}
int main(void){


	int t, n, m;
	vector<NODE> q;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		q.clear();
		for(int i = 0; i<n; ++i){
			NODE node;
			node.num = i;
			scanf("%d", &node.pri);
			q.push_back(node);
		}
		printf("%d\n", search(q, m));

	}
	return 0;
}

