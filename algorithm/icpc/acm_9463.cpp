#include<cstdio>
int T, N, a[100001], b[100001], tree[100001];
void update(int i){
	while(i<=N){
		++tree[i];
		i+=i&-i;
	}
}
int query(int i){
	int ret=0;
	while(i>0){
		ret+=tree[i];
		i-=i&-i;
	}
	return ret;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		for(int i=1;i<=N;++i)	scanf("%d", &a[i]);
		for(int i=1;i<=N;++i){
			int t;
			scanf("%d", &t);
			b[t]=i;
		}
		long long ans=0;
		for(int i=N;i>0;--i){
			ans+=(long long)query(b[a[i]]);
			update(b[a[i]]);
		}
		printf("%lld\n", ans);
		for(int i=1;i<=N;++i)	tree[i]=0;
	}
}
