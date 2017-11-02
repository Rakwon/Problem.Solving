#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#define INF 999999999
using namespace std;
typedef pair<int, int> P;

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void dijkstra(vector<vector<P> >g, int start, int destination){

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

		visited[v] = 1;

		int len = g[v].size();
		for(int i = 0; i<len; ++i){
			int next = g[v][i].first, d = g[v][i].second;
			if(dist[next] > dist[v] + d){
				dist[next] = dist[v] + d;
				pq.push(P(dist[next], next));
			}
		}
	}


	printf("%d", dist[destination]);
}
int main(void){

	int n, m, num = 0;
	P map[101][101];
	vector<vector<P> > g;

	scanf("%d %d", &m, &n);

	for(int i = 0; i<n; ++i){
		for(int j = 0; j<m; ++j){
			scanf("\n%1d", &map[i][j].first);
			map[i][j].second = num++;
		}
	}


	g.assign(n*m+1, vector<P>());

	for(int i = 0; i<n; ++i){
		for(int j = 0; j<m; ++j){
			for(int k = 0; k<4; ++k){
				if( (i + dy[k] >=0 && i + dy[k] < n) && (j+ dx[k]>=0 && j+dx[k]<m)){
					// map[i][j].first = weight, map[i][j].second = node;
					//printf("%d -> %d(%d %d)\n", map[i][j].second, map[i+dy[k]][j+dx[k]].second, i+dy[k], j+dx[k]);
					g[map[i][j].second].push_back(P(map[i+dy[k]][j+dx[k]].second, map[i+dy[k]][j+dx[k]].first));
				}
			}
		}
	}

	dijkstra(g, 0, num-1);
	return 0;
}

