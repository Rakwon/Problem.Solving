#include <iostream>
#include <functional>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <queue>

using namespace std;
typedef pair<int, int> E;
typedef pair< int, E > V;
priority_queue<V, vector<V>, greater<V> > pq;

int parent[10001], size[10001];
void init(){
	for(int i = 0; i<10001; ++i){
		parent[i] = i;
		size[i] = 1;
	}
}

int find(int p){
	if(parent[p] == p) return p;
	else return parent[p] = find(parent[p]);
}

void uni(int p, int q){

	if(size[p] > size[q]){
		parent[q] = p;
		size[p] += size[q];
	}
	else{
		parent[p] = q;
		size[q] += size[p];
	}
}

int main(void){

	int n, m, f, t, w, ans = 0;

	scanf("%d %d", &n, &m);
	for(int i = 0; i<m; ++i){
		scanf("%d %d %d", &f, &t, &w);
		pq.push(V(w,E(f,t)));
	}

	init();
	while(!pq.empty()){

		int p = find(pq.top().second.first);
		int q = find(pq.top().second.second);


		if(p != q){
			ans += pq.top().first;
			uni(p, q);
		}
		pq.pop();
	}

	printf("%d", ans);
	return 0;

}

