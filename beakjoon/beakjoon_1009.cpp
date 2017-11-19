#include <cstdio>

int getProcessComputer(int a, int b){

	int ret = a;
	while(--b){
		ret *= a;
		ret %= 10;
	}

	if(ret == 0) return 10;
	else return ret;
}
int main(void){

	int T, a, b;
	scanf("%d", &T);
	while(T--){
		scanf("%d %d",&a, &b);
		printf("%d\n", getProcessComputer(a, b));
	}
	return 0;
}

