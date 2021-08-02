#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
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
int par[40001][17], depth[40001], dp[40001];
vector<vector<pii> > adj;
void makeTree(){
	queue<int> Q;
	depth[1]=1;
	Q.push(1);
	while(Q.size()){
		int v=Q.front();Q.pop();
		for(pii &p:adj[v]){
			int n=p.first;
			if(depth[n])	continue;
			depth[n]=depth[v]+1;par[n][0]=v;dp[n]=dp[v]+p.second;
			Q.push(n);
		}
	}
}
void dfs(int u, int v){
	for(pii &p:adj[v]){
		int n=p.first;
		if(n==u)	continue;
		par[n][0]=v;depth[n]=depth[v]+1;dp[n]=dp[v]+p.second;
		dfs(v, n);
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
	int N, K, a, b, c;
	N=readInt();
	adj=vector<vector<pii> >(N+1);
	for(int i=1;i<N;++i){
		a=readInt();b=readInt();c=readInt();
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	depth[1]=1;
	makeTree();
	for(int k=1;k<17;++k)for(int i=1;i<=N;++i)
		par[i][k]=par[par[i][k-1]][k-1];
	K=readInt();
	while(K--){
		a=readInt();b=readInt();
		printf("%d\n", dp[b]+dp[a]-dp[lca(a, b)]*2);
	}
	return 0;
}
