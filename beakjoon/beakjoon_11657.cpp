#include <cstdio>
#include <iostream>
#include <vector>
#include <utility>

using namespace std;

typedef pair<int, int> P;
#define INF 1000000000

int main(void){

	int n, m, f, t, w;
	vector<vector<P> > g;
	vector<int> dist;
	scanf("%d %d", &n, &m);

	g.assign(n+1, vector<P>());
	dist.assign(n+1, INF);

	for(int i = 0; i<m; ++i){
		scanf("%d %d %d", &f, &t, &w);
		g[f].push_back(P(t, w));

	}

	dist[1] = 0;
	int update = 0;
	for(int i = 1; i<=n; ++i){

		for(int j = 1; j<=n; ++j){

			int len = g[j].size();

			for(int k = 0; k<len; ++k){
				int next = g[j][k].first, d = g[j][k].second;
				if(dist[j] != INF && dist[next] > dist[j] + d){
					dist[next] =  dist[j] + d;
					if(i == n)	update = 1;
				}
			}
		}
	}

	if(update) printf("-1");
	else{
		for(int i = 2; i<=n; ++i)
			printf("%d\n", dist[i] == INF ? -1 : dist[i]);
	}

	return 0;
}

