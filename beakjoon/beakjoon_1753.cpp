#include <cstdio>
#include <functional>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

#define INF 99999999
#define MAX_V 20001
typedef pair<int, int> P;
vector<P> adj[MAX_V];


void dijkstra(int v, int n){

	int dist[MAX_V];
	int visited[MAX_V];
	int cur;
	priority_queue<P, vector<P>, greater<P> > pq;

	for(int i = 0; i<MAX_V; ++i){
		dist[i] = INF;
		visited[i] = 0;
	}

	dist[v] = 0;
	pq.push(P(dist[v], v));

	while(!pq.empty()){

		do{
			cur = pq.top().second;
			pq.pop();
		}while(!pq.empty() && visited[cur]);

		if(visited[cur]) break;
		visited[cur] = 1;

		int len = adj[cur].size();
		for(int i = 0; i<len; ++i){
			int next = adj[cur][i].first, d = adj[cur][i].second;
			if(dist[next] > dist[cur] + d){
				dist[next] = dist[cur] + d;
				pq.push(P(dist[next], next));
			}
		}
	}

	for(int i = 1; i<=n ;++i){
		if(dist[i] == INF) printf("INF\n");
		else printf("%d\n", dist[i]);
	}
}
int main(void){

	int n,m,v,from,to, w;
	scanf("%d %d %d", &n, &m, &v);
	for(int i = 0; i<m; ++i){
		scanf("%d %d %d", &from, &to, &w);
		adj[from].push_back(P(to, w));
	}

	dijkstra(v, n);
	return 0;
}

