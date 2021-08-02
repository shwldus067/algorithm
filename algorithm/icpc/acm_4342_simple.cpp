#include<stdio.h>
bool sol(int a, int b){
	return !(a%b)||(a-b>b)||!sol(b, a%b);
}
int main(){
	int a, b;
	while(scanf("%d %d", &a, &b), a){
		printf("%c wins\n", sol(a, b)^(a<b)?'A':'B');
	}
}
