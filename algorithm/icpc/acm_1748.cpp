#include<cstdio>
int main(){
	int N, ans=0;
	scanf("%d", &N);
	for(int i=1;i<=N;i*=10)	ans+=N-i+1;
	printf("%d\n", ans);
	return 0;
}
