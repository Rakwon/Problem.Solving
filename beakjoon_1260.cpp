#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;


void dfs(int);
void bfs(int);

int N, M, V;
vector<int> visited;
vector<vector<int> > g;

int main(void){

	int from, to;

	scanf("%d %d %d", &N, &M, &V);
	g.assign(N+1, vector<int>());

	visited.assign(N+1, 0);
	for(int i = 0; i<M; ++i){
		scanf("%d %d", &from, &to);
		g[from].push_back(to);
		g[to].push_back(from);
	};

	for(int i = 1; i<=N; sort(g[i].begin(), g[i].end()), ++i);

	dfs(V);
	printf("\n");
	bfs(V);

	return 0;
}
void dfs(int next){

	int len = g[next].size();
	visited[next] = 1;
	printf("%d ", next);

	for(int i = 0; i<len; ++i){
		if(visited[g[next][i]] == 0){
			dfs(g[next][i]);
		}
	}
}
void bfs(int start){

	queue<int> q;
	visited.assign(N+1, 0);
	visited[start] = 1;
	q.push(start);

	while(q.size() > 0){

		int next = q.front();q.pop();
		printf("%d ", next);
		int len = g[next].size();

		for(int i = 0; i<len; ++i){
			if(visited[g[next][i]] == 0){
				visited[g[next][i]] = 1;
				q.push(g[next][i]);
			}
		}
	}
}


