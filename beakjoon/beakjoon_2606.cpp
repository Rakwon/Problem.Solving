#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

typedef pair<int, int> P;
vector<vector<int> > g;
vector<int> visited;
int ans;

int DFS(int v){

	visited[v] = 1;

	int con = 0;
	int len = g[v].size();
	for(int i = 0; i<len; ++i){
		int next = g[v][i];
		if(!visited[next]){
			con += (DFS(next) + 1);
		}
	}

	return con;
}
int main(void){

	int n, m, f, t;


	scanf("%d %d", &n,&m);

	g.assign(n+1, vector<int>());
	visited.assign(n+1, 0);

	for(int i = 0; i<m; ++i){
		scanf("%d %d", &f, &t);
		g[f].push_back(t);
		g[t].push_back(f);
	}

	printf("%d", DFS(1));

	return 0;
}

