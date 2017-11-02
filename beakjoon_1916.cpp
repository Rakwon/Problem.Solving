#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
using namespace std;

typedef pair<int, int> P;

#define INF 999999999

void dijkstra(vector<vector<P> > adj, int start, int desti){

	int node_num = adj.size();
	int dist[node_num];
	int visited[node_num];
	int min, v;

	for(int i = 1; i<node_num; ++i){
		dist[i] = INF;
		visited[i] = 0;
	}

	dist[start] = 0;
	for(int i = 1; i<node_num; ++i){
		min = INF;
		for(int j = 1; j<node_num; ++j){
			if(!visited[j] && min > dist[j]){
				min = dist[j];
				v = j;
			}
		}

		if( min == INF || visited[v] ) break;
		visited[v] = 1;

		int len = adj[v].size();
		for(int j = 0; j<len; ++j){
			int next = adj[v][j].first, d = adj[v][j].second;
			if(dist[next] > dist[v] + d)
				dist[next] = dist[v] + d;
		}
	}

	printf("%d\n", dist[desti]);
}
int main(void){

	int n,m, f, t, w, v, u;
	vector<vector<P> > adj;

	scanf("%d %d", &n, &m);
	adj.assign(n+1, vector<P>());
	for(int i = 0; i<m; ++i){
		scanf("%d %d %d", &f, &t, &w);
		adj[f].push_back(P(t,w));
	}

	scanf("%d %d", &v, &u);
	dijkstra(adj, v, u);
	return 0;
}

