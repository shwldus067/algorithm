#include<cstdio>
int cost[100], par[100];
int find(int u){
	return par[u]= u==par[u]?u:find(par[u]);
}
void merge(int u, int v){
	u=find(u);v=find(v);
	if(u==v)	return;
	if(cost[u]<=cost[v])	par[v]=u;
	else	par[u]=v;
}
int main(){
	int N, ans=0;
	char adj[101];
	bool visit[100][100];
	bool chk[100]={0, };
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%d", &cost[i]), par[i]=i;
	for(int i=0;i<N;++i){
		scanf("%s", adj);
		for(int j=0;j<N;++j){
			if(adj[j]=='1')	visit[i][j]=1;
			else visit[i][j]=0;
		}
	}
	for(int k=0;k<N;++k){
		for(int i=0;i<N;++i){
			for(int j=0;j<N;++j){
				if(visit[i][k] && visit[k][j])	visit[i][j]=1;
			}
		}	
	}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(visit[i][j] && visit[j][i])	merge(i, j);
		}
	}
	for(int i=0;i<N;++i){
		int p=find(i);
		if(!chk[p]){
			ans+=cost[p];
			chk[p]=1;
		}
	}
	printf("%d\n", ans);
	return 0;
}
