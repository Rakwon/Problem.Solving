#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b){
	return a > b ? a : b;
}
int min(int a, int b){
	return a > b ? b : a;
}
vector<vector<int> > input(void){

	int n, m, a;
	vector<vector<int> >map;
	scanf("%d %d", &n, &m);
	map.assign(n, vector<int>());

	for(int i =0; i<n; ++i){
		for(int j = 0; j<m; ++j){
			scanf("%1d", &a);
			map[i].push_back(a);
		}
	}

	return map;
}
int search(vector<vector<int> > map, int y, int x, int row, int col){

	int dist = min(row, col) - 1;
	for(int d = dist; d >= 1; --d ){
		int _y = y+d;
		int _x = x+d;
		if(_y < row && _x < col){
			if(map[y][x] == map[_y][x] && map[y][x] == map[y][_x] && map[y][x] == map[_y][_x]){
				return (d+1)*(d+1);
			}
		}
	}

	return 1;
}
void process(vector<vector<int> > map){

	int row = map.size();
	int col = map[0].size();
	int ans = 1;

	for(int i = 0; i<row; ++i)
		for(int j = 0; j<col; ++j)
			ans = max(ans, search(map, i, j, row, col));

	printf("%d", ans);

}
int main(void){

	process(input());
	return 0;
}

