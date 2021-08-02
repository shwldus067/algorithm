#include<cstdio>
#include<vector>
using namespace std;
char buf[1<<17];
inline char read(){
	static int idx=1<<17;
	if(idx==1<<17){
		fread(buf, 1, 1<<17, stdin);
		idx=0;
	}
	return buf[idx++];
}
inline int readInt(){
	int sum=0;
	char cur=read();
	while(cur==10 || cur==32)	cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	return sum;
}
int par[50001][17], depth[50001];
vector<int> adj[50001];
void dfs(int u, int v, int d){
	par[v][0]=u;
	depth[v]=d;
	for(int &n:adj[v]){
		if(n==u)	continue;
		dfs(v, n, d+1);
	}
}
int lca(int u, int v){
	if(depth[u]<depth[v])	swap(u, v);
	int t=depth[u]-depth[v];
	for(int k=0;k<17;++k)if(t&(1<<k))	u=par[u][k];
	if(u==v)	return u;
	for(int k=16;k>=0;--k){
		if(par[u][k]!=par[v][k]){
			u=par[u][k];
			v=par[v][k];
		}
	}
	return par[u][0];
}
int main(){
	int N, M, a, b;
	N=readInt();
	for(int i=1;i<N;++i){
		a=readInt();b=readInt();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 1, 0);
	for(int k=1;k<17;++k)for(int i=1;i<=N;++i)
		par[i][k]=par[par[i][k-1]][k-1];
	M=readInt();
	while(M--){
		a=readInt();b=readInt();
		printf("%d\n", lca(a, b));
	}
	return 0;
}
