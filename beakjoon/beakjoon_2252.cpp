#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <stack>
#include <utility>
using namespace std;
void sorting(int v, vector<vector<int> > &g, vector<int>  &visited, stack<int> &stack){

	visited[v] = 1;
	int n = g[v].size();
	for(int i = 0; i<n; ++i){
		int next = g[v][i];
		if(!visited[next]){
			sorting(next, g, visited, stack);
		}
	}

	stack.push(v);
}
void TopologicalSort(vector<vector<int> >g){

	int node_num = g.size();
	vector<int> visited(node_num, 0);
	stack<int> node;

	for(int v = 1; v != node_num; ++v){
		if(!visited[v])
			sorting(v, g, visited, node);
	}
	for(;!node.empty(); printf("%d ", node.top()), node.pop());
}
int main(void){

	int n, m, f, t;
	vector<vector<int> > g;

	scanf("%d %d", &n, &m);
	g.assign(n+1, vector<int>());
	for(int i = 0; i<m; ++i){
		scanf("%d %d", &f, &t);
		g[f].push_back(t);
	}

	TopologicalSort(g);
	return 0;
}

