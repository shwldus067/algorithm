#include<cstdio>
int p[1001];
int parent(int a){
	return a==p[a]?a:parent(p[a]);
}
void merge(int u, int v){
	u=parent(u), v=parent(v);
	if(u<v)	p[v]=u;
	else	p[u]=v;
}
int main(){
	int N, M, e[1001]={0, };
	scanf("%d%d", &N, &M);
	for(int i=1;i<=N;++i)	p[i]=i;
	while(M--){
		char r;
		int a, b;
		scanf(" %c%d%d", &r, &a, &b);
		if(r=='F'){
			merge(a, b);
		}else{
			if(e[a])	merge(e[a], b);
			if(e[b])	merge(e[b], a);
			e[a]=b, e[b]=a;
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i){
		if(p[i]==i)	ans++;
	}
	printf("%d\n", ans);
	return 0;
}
