#include<cstdio>
int N, M, par[201];
int find(int u){
	int &ret=par[u];
	while(ret!=par[ret])	ret=par[ret];
	return ret;
}
void merge(int u, int v){
	u=find(u);v=find(v);
	if(u==v)	return;
	if(u<v)	par[v]=u;
	else	par[u]=v;
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;++i)	par[i]=i;
	int t;
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
		scanf("%d", &t);
		if(t)	merge(i, j);
	}
	int pre, cur;
	scanf("%d", &pre);
	for(int i=1;i<M;++i){
		scanf("%d", &cur);
		if(find(pre)!=find(cur)){
			printf("NO\n");
			return 0;
		}
		pre=cur;
	}
	printf("YES\n");
	return 0;
}
