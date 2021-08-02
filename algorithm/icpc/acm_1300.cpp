#include<cstdio>
#define min(a, b) a<b?a:b
int N, K;
int main(){
	scanf("%d %d", &N, &K);
	int l=1, r=K, ans;
	while(l<=r){
		long long cnt=0;
		int m=(l+r)/2, i;
		for(i=1;i*i<=m;++i)	cnt+=min(m/i, N);
		cnt=cnt*2-(i-1)*(i-1);
		if(cnt<K)	l=m+1;
		else	ans=m, r=m-1;
	}
	printf("%d\n", ans);
	return 0;
}
