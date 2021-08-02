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
int sz[100001], dep[100001], par[100001], top[100001];
vector<int> adj[100001];
void dfs1(int u, int v){
	sz[v]=1;
	for(int i=0;i<adj[v].size();++i){
		int &n=adj[v][i];
		if(u==n){
			swap(n, adj[v].back());
			adj[v].erase(adj[v].end()-1);
			if(u==n)	return;
		}
		dep[n]=dep[v]+1;par[n]=v;
		dfs1(v, n);sz[v]+=sz[n];
		if(sz[n]>sz[adj[v][0]])	swap(n, adj[v][0]);
	}
}
void dfs2(int v){
	for(int &n:adj[v]){
		top[n]=(n==adj[v][0]?top[v]:n);
		dfs2(n);
	}
}
int lca(int u, int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])	swap(u, v);
		u=par[top[u]];
	}
	if(dep[u]>dep[v])	return v;
	return u;
}
int main(){
	int N, M, a, b;
	N=readInt();
	for(int i=1;i<N;++i){
		a=readInt();b=readInt();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	top[1]=1;
	dfs1(0, 1);dfs2(1);
	M=readInt();
	while(M--){
		a=readInt();b=readInt();
		printf("%d\n", lca(a, b));
	}
	return 0;
}
