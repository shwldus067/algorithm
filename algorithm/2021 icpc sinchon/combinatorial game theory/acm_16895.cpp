#include<cstdio>
int main(){
	int N, P[1000], t=0, ans=0, p=1;
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", P+i), t^=P[i];
	if(!t)	printf("0\n");
	else{
		while(p*2<=t)	p*=2;
		for(int i=0;i<N;++i)if(P[i]&p)	++ans;
		printf("%d\n", ans);
	}
	return 0;
}
