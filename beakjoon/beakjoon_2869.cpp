/*
 * 풀이
 * 만약 남은 거리가 a 이하이면 한번에 갈 수 있음.
 * 따라서 총 거리에서 a를 뺀 거리를 몇번에 갈 수 있는지 찾는다.
 * 전체 거리에서 a를 뺸 거리를 left라 하자
 * a-b는 하루에 갈 수 있는 거리 이므로 left를 (a-b)로 나눈 몫이 left 가 된다.
 * 만야 left를 (a - b)로 나눈 나머지가 생기면 하루를 더 가야함.
 * 
 * 따라서 나눈 나머지가 0이면 1을 더하고( 처음에 뺸 a를 가야하므로)
 * 나머지가 생기면 하루를 더가야하므로 2를 더한다.
 * 
 */

#include <cstdio>

int main(void){

	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	int left = c - a;
	int incre = a - b;
	int ans = left / incre;
	if( left % incre  == 0)
		ans += 1;
	else
		ans += 2;

	printf("%d", ans);

	return 0;
}

