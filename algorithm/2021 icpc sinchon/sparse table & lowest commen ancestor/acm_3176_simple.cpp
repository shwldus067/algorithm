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
int cost[100001], sz[100001], dep[100001], par[100001];
int top[100001], in[100001], cnt;
int mseg[1<<18], Mseg[1<<18], base=1<<17, mans, Mans;
vector<pii> adj[100001];
void init(){
	for(int i=base-1;i;--i){
		int j=i*2;
		Mseg[i]=max(Mseg[j], Mseg[j|1]);
		mseg[i]=min(mseg[j], mseg[j|1]);
	}
}
void query(int l, int r){
	l+=base-1, r+=base-1;
	mans=1e9, Mans=0;
	while(l<=r){
		if(l&1)	mans=min(mans, mseg[l]), Mans=max(Mans, Mseg[l++]);
		if(!(r&1))	mans=min(mans, mseg[r]), Mans=max(Mans, Mseg[r--]);
		l>>=1, r>>=1;
	}
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
void sol(int u, int v){
	int mm=1e9, MM=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]])	swap(u, v);
		int a=top[u];
		query(in[a], in[u]);
		mm=min(mm, mans), MM=max(MM, Mans);
		u=par[a];
	}
	mans=mm, Mans=MM;
	if(u==v)	return;
	if(dep[u]>dep[v])	swap(u, v);
	int nxt=adj[u][0].first;
	query(in[nxt], in[v]);
	mm=min(mm, mans);
	MM=max(MM, Mans);
	mans=mm, Mans=MM;
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
	for(int i=1;i<=N;++i)	mseg[in[i]+base-1]=Mseg[in[i]+base-1]=cost[i];
	init();
	M=readInt();
	while(M--){
		a=readInt();b=readInt();
		sol(a, b);
		printf("%d %d\n", mans, Mans);
	}
	return 0;
}
