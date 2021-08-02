#include<stdio.h>
int sol(int a, int b, int t){
	if(b%a==0)	return t;
	if(b-a>a)	return t;
	return sol(b-a, a, t^1);
}
int main(){
	int a, b, res;
	while(1){
		scanf("%d %d", &a, &b);
		if(!a)	break;
		if(a<b)	res=sol(a, b, 0);
		else	res=sol(b, a, 0);
		if(res)	printf("B wins\n");
		else	printf("A wins\n");
	}
	return 0;
}
