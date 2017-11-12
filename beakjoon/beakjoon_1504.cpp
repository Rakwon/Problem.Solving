#include <cstdio>
#include <utility>
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;

#define INF 99999999
typedef pair<int ,int> P;

int min(int a, int b){
	return a > b ? b : a;
};

vector<int> dijkstra(vector<vector<P> > g, int start){

	int v, n = g.size();
	vector<int> dist(n, INF);
	vector<int> visited(n, 0);
	priority_queue<P, vector<P>, greater<P> > pq;

	dist[start] = 0;
	pq.push(P(dist[start], start));

	while(!pq.empty()){

		do{
			v = pq.top().second;
			pq.pop();
		}while(!pq.empty() && visited[v]);

		if(visited[v] || dist[v] == INF) break;

		visited[v] = true;

		int len = g[v].size();
		for(int i = 0; i<len; ++i){
			int next = g[v][i].first, d = g[v][i].second;

			if(dist[next] > dist[v] + d){
				dist[next] = dist[v] + d;
				pq.push(P(dist[next], next));
			}
		}
	}

	return dist;
}
int main(void){


	int n, e, f, t, w, by1, by2;
	vector<vector<P> > g;

	scanf("%d %d", &n, &e);
	g.assign(n+1, vector<P>());

	for(int i = 0; i<e; ++i){
		scanf("%d %d %d", &f, &t, &w);
		g[f].push_back(P(t, w));
		g[t].push_back(P(f, w));
	}
	scanf("%d %d", &by1, &by2);

	vector<int> go = dijkstra(g, 1);
	vector<int> by = dijkstra(g, by1);
	vector<int> andGo = dijkstra(g, n);

	int ans;
	if(go[n] == INF || go[by1] == INF || go[by2] == INF || by[by2] == INF)
		ans = -1;
	else
		ans = min(go[by1] + by[by2]+ andGo[by2], go[by2] + by[by2] + andGo[by1]);
	printf("%d", ans);
	return 0;
}

