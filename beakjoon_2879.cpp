/*
 * 입력 크기가 1000이므로 O(n^2) 까지 가
 * 
 * 풀이
 * 일단 그룹으로 묶므면 연산(탭을 뺴거나 더하거나) 횟수를 줄일 수 있음
 * 따라서 최대한 그룹으로 묶어 연산을 수행.
 * 그룹으로 수행 할 경우 올바른 탭 횟수와 맞지 않는 경우 발생.
 * 따라서 for구문에서 i를 증가시키지 않고 처음부터 그룹을 묶는 동작을 수행.
 * 현재 위치(i)에 탭 회수가 일치하면 그때 i를 증가 시킨다.
 * 
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
#include <vector>
using namespace std;

int n;
vector<int> cur, cor;
void input();
void process();
int min(int, int);

int main(void){

	input();
	process();
	return 0;
}
int min(int a, int b){
	return a > b ? b : a;
}
void input(){

	scanf("%d", &n);

	cur.assign(n, 0);
	cor.assign(n, 0);

	for(int i = 0; i<n; scanf("\n%d", &cur[i++]));
	for(int i = 0; i<n; scanf("\n%d", &cor[i++]));
}
void process(){

	int ans = 0;
	int s ,e;
	stack<int> del;
	stack<int> add;

	for(int i = 0; i<n; ){
		s = e = i;
		if(cur[i] > cor[i]){

			int cnt = cur[e] - cor[e];
			while(e < n && cur[e] > cor[e] ){
				cnt = min(cnt, cur[e] - cor[e]);
				del.push(e++);
			}
			while(!del.empty()){
				cur[del.top()] -= cnt;
				del.pop();
			}
			ans += cnt;
		}
		else if(cur[i] < cor[i]){

			int cnt = cor[i] - cur[i];
			while( e < n && cur[e] < cor[e]){
				cnt = min(cnt, cor[e] - cur[e]);
				add.push(e++);
			}

			while(!add.empty()){
				cur[add.top()] += cnt;
				add.pop();
			}
			ans += cnt;
		}
		else
			++i;
	}

	printf("%d\n", ans);
}


