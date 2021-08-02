#include<cstdio>
#include<vector>
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
int cost[40001], sz[40001], dep[40001], par[40001];
int top[40001], in[40001], cnt;
int seg[1<<17], base=1<<16;
vector<pii> adj[40001];
void init(){
	for(int i=base-1;i;--i){
		int j=i*2;
		seg[i]=seg[j]+seg[j|1];
	}
}
int query(int l, int r){
	l+=base-1, r+=base-1;
	int ret=0;
	while(l<=r){
		if(l&1)	ret+=seg[l++];
		if(!(r&1))	ret+=seg[r--];
		l>>=1, r>>=1;
	}
	return ret;
}
void dfs1(int u, int v){
	sz[v]=1;
	for(int i=0;i<adj[v].size();++i){
		pii &p=adj[v][i];
		if(u==p.first){
			swap(p, adj[v].back());
			adj[v].erase(adj[v].end()-1);
			if(u==p.first)	return;
		}
		int n=p.first, d=p.second;
		dep[n]=dep[v]+1;par[n]=v;
		dfs1(v, n);sz[v]+=sz[n];
		if(sz[n]>sz[adj[v][0].first])	swap(p, adj[v][0]);
	}
}
void dfs2(int v){
	in[v]=++cnt;
	for(pii &p:adj[v]){
		int n=p.first;
		top[n]=(p==adj[v][0]?top[v]:n);
		dfs2(n);
		cost[n]=p.second;
	}
}
int sol(int u, int v){
	int ret=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])	swap(u, v);
		int a=top[u];
		ret+=query(in[a], in[u]);
		u=par[a];
	}
	if(u==v)	return ret;
	if(dep[u]>dep[v])	swap(u, v);
	int nxt=adj[u][0].first;
	ret+=query(in[nxt], in[v]);
	return ret;
}
int main(){
	int N, M, a, b, c;
	N=readInt();
	for(int i=1;i<N;++i){
		a=readInt();b=readInt();c=readInt();
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	top[1]=1;
	dfs1(0, 1);dfs2(1);
	for(int i=1;i<=N;++i)	seg[in[i]+base-1]=cost[i];
	init();
	M=readInt();
	while(M--){
		a=readInt();b=readInt();
		printf("%d\n", sol(a, b));
	}
	return 0;
}
