#include <cstdio>
#include <cstdlib>
#include <cstring>

#define INF 999999999
int table[1000010];

int min(int a ,int b){
	return a > b ? b : a;
}

void tableClear(){
	for(int i = 0; i<1000010; ++i){
		table[i] = INF;
	}
}
int search(int n){

	if(n <= 1) return 0;

	int i3, i2, m1;
	i3 = i2 = m1 = INF;

	// 3으로 나눌 수 있으면
	if(n%3 == 0)
		i3 = table[n/3] == INF ? search(n/3) + 1 : table[n/3] + 1;
	//2로 나눌 수 있으면
	if(n%2 == 0)
		i2 = table[n/2] == INF ? search(n/2) + 1 : table[n/2] + 1;
	// -1의 경우
	m1 = table[n-1] == INF ? search(n-1) + 1 : table[n-1] + 1;

	return table[n] = min(m1, min(i2, i3));
}

int main(void){

	int n;
	tableClear();
	scanf("%d", &n);
	printf("%d\n", search(n));
	return 0;
}

