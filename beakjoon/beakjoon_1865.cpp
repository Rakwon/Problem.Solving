#include <cstdio>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define INF 999999999
typedef pair<int, int> P;
int dist[501];

void bellman_ford(vector<vector<P> >g, int start){

	dist[start] = 0;

	int update = 0;
	int n = g.size();
	for(int i = 1; i< n; ++i){
		update = 0;
		for(int j = 1; j<n; ++j){
			int len = g[j].size();
			for(int k = 0; k<len; ++k){
				int next = g[j][k].first, d = g[j][k].second;
				if(dist[j] != INF && dist[next] > dist[j] + d){
					dist[next] = dist[j] + d;
					update = 1;
				}
			}
		}
	}

	if( update ) printf("YES\n");
	else printf("NO\n");
};

void clear_dist(){
	for(int i = 0; i<501; ++i) dist[i] = INF;
};

int main(void){

	int t, n, m, w, ff, tt, ww;
	vector<vector<P> > g;

	scanf("%d", &t);

	while(t--){
		scanf("%d %d %d", &n, &m, &w);

		g.assign(n+1, vector<P>());
		clear_dist();

		for(int i = 0; i<m; ++i){
			scanf("%d %d %d", &ff, &tt, &ww);
			g[ff].push_back(P(tt, ww));
			g[tt].push_back(P(ff, ww));
		}

		for(int i = 0; i<w; ++i){
			scanf("%d %d %d", &ff, &tt, &ww);
			g[ff].push_back(P(tt, (-1)*ww));
		}


		bellman_ford(g, 1);

	}

	return 0;
}

