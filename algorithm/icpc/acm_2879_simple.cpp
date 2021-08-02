#include<stdio.h>
int main(){
	int N, A[1000], ans=0, tmp=0;
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", A+i);
	for(int i=0;i<N;++i)	scanf("%d", &tmp), A[i]-=tmp;
	int m=A[0], a, b;
	for(int i=1;i<N;m=A[i++]){
		if(m*A[i]<0)	ans+=(m<0 ? -m:m);
		else if((a=(m<0?-m:m))>(b=(A[i]<0?-A[i]:A[i])))	ans+=a-b;
	}
	printf("%d\n", ans+(m<0 ? -m:m));
	return 0;
}
