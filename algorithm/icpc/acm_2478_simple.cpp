#include<stdio.h>
int a[500], N, k1, k2, q, l, r;
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		scanf("%d", a+i);
		--a[i];
	}
	r=N-1;
	for(int i=0;i<N;++i){
		if((a[(i-1+N)%N]-1+N)%N!=a[i] && a[i]==(a[(i+1)%N]+1)%N)
			l=i;
		if((a[(i-1+N)%N]-1+N)%N==a[i] && a[i]!=(a[(i+1)%N]+1)%N)
			r=i;
	}
	k2=N-l;
	q=(r+k2)%N;
	k1=a[r];
	printf("%d\n1 %d\n%d", k1?k1:N, q+1, k2?k2:N);
	return 0;
}
