#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <stack>
using namespace std;

double v[26];

void process(char *);
int main(void){

	int n;
	char cal[110];

	scanf("%d %s", &n, cal);
	for(int i = 0; i < n ; scanf("\n%lf", &v[i++]));

	process(cal);
	return 0;
}

void process(char* cal){

	stack<double> stack;
	int len = strlen(cal);
	for(int i = 0; i<len; ++i){

		if(cal[i] - 'A' >= 0 && cal[i] -'A'<=25){
			stack.push(v[cal[i] - 'A']);
		}
		else{
			double b= stack.top(); stack.pop();
			double a = stack.top(); stack.pop();

			switch(cal[i]){
			case '+' :
				stack.push(a+b);
				break;
			case '-' :
				stack.push(a-b);
				break;
			case '*' :
				stack.push(a*b);
				break;
			case '/' :
				stack.push(a/b);
				break;
			}
		}
	}
	printf("%.2lf", stack.top());
}

