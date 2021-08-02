#include<cstdio>
int A[1<<20];
int main(){
	int a;
	while(~scanf("%d", &a)){
		if(!(A[a>>5]&(1<<(a&31)))){
			printf("%d ", a);
			A[a>>5]|=(1<<(a&31));
		}
	}
	return 0;
}
