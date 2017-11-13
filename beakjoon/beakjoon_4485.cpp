#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <utility>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

#define INF 99999999

typedef pair<int ,int> P;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

int Min(int a, int b){
	return a > b ? b : a;
}
int Dijkstra(vector<vector<P> > g, int sd){

	int len = g.size(), v;
	int dist[len], visited[len];
	priority_queue<P, vector<P>, greater<P> > pq;

	for(int i = 0; i<len; ++i)
		dist[i] = INF, visited[i] = 0;

	dist[1] = sd;

	pq.push(P(dist[1], 1));

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

	return dist[len-1] ;
}
int main(void){

	int n;
	vector<vector<P> > g;
	P map[126][126];

	for(int i=1;1;++i){
		scanf("%d", &n);
		if(n == 0) break;

		//입력
		for(int i = 1; i<=n; ++i){
			for(int j = 1; j<=n; ++j){
				scanf("%d", &map[i][j].second);
				map[i][j].first = (i-1)*n + j;
			}
		}

		g.assign(n*n+1, vector<P>());
		for(int i = 1; i<=n; ++i){
			for(int j = 1; j<=n; ++j){

				int v = (i-1)*n + j;

				for(int k = 0; k<4; ++k){
					int y = i + dy[k], x = j + dx[k];
					if((y >= 1 && y <=n) && ( x >= 1 && x <=n)){
						int u = map[i+dy[k]][j+dx[k]].first, d = map[i+dy[k]][j+dx[k]].second;
						g[v].push_back(P(u, d));
					}
				}
			}
		}
		printf("Problem %d: %d\n",i,  Dijkstra(g, map[1][1].second));
	}
	return 0;
}

