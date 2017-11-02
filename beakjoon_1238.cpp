#include <cstdio>
#include <utility>
#include <iostream>
#include <functional>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define INF 99999999
typedef pair<int, int> P;

int max(int a, int b){
	return a > b ? a : b;
}
vector<int> dijkstra(vector<vector<P> >g, int start){

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

		if(visited[v]) break;
		visited[v] = true;

		int len = g[v].size();
		for(int i = 0; i<len; ++i){
			int next = g[v][i].first;
			int d = g[v][i].second;

			if(dist[next] > dist[v] + d){
				dist[next] = dist[v] + d;
				pq.push(P(dist[next], next));
			}
		}
	}

	return dist;

}

int main(void){

	int n, m, x, f, t, w, ans = -1;
	vector<vector<P> > g, rg;

	scanf("%d %d %d\n", &n, &m, &x);

	g.assign(n+1, vector<P>());
	rg.assign(n+1, vector<P>());

	for(int i = 0; i<m; ++i){
		scanf("%d %d %d", &f, &t, &w);
		g[f].push_back(P(t, w));
		rg[t].push_back(P(f, w));
	}

	vector<int> come = dijkstra(g, x);
	vector<int> go = dijkstra(rg, x);

	for(int i = 1; i<n+1; ++i)
		ans = max(ans, come[i] + go[i]);

	printf("%d", ans);

	return 0;
}

