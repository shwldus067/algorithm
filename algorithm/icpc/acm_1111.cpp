#include<stdio.h>
int main(){
	int N, a[50], i, A, B, f=1;
	scanf("%d", &N);
	for(i=0;i<N;++i)	scanf("%d", a+i);
	if(N==1)	printf("A\n");
	else if(N==2){
		if(a[0]==a[1])	printf("%d\n", a[0]);
		else	printf("A\n");
	}
	else{
		int x=a[1]-a[2], y=a[0]-a[1], z=a[0]*a[2]-a[1]*a[1];
		if(y==0)	A=1, B=0;
		else if(x%y==0 && z%y==0)	A=x/y, B=z/y;
		else	f=0;
		if(f){
			for(i=1;i<N;++i){
				if(a[i]!=(a[i-1]*A+B)){
					f=0;break;
				}
			}
		}
		if(f)	printf("%d\n", a[N-1]*A+B);
		else	printf("B\n");
	}
	return 0;
}
