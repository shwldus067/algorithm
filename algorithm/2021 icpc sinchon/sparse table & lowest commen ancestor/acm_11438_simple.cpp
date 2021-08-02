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
int par[200001][19], depth[100001];
int in[100001], out[100001], cnt;
vector<int> adj[100001];
void dfs(int u, int v){
	in[v]=++cnt;
	par[cnt][0]=v;
	depth[v]=depth[u]+1;
	for(int &n:adj[v]){
		if(n==u)	continue;
		dfs(v, n);
	}
	out[v]=++cnt;
	par[cnt][0]=u;
}
int main(){
	int N, M, a, b;
	N=readInt();
	for(int i=1;i<N;++i){
		a=readInt();b=readInt();
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(0, 1);
	for(int k=1;k<19;++k)for(int i=1;i<=cnt-(1<<k)+1;++i){
		a=par[i][k-1], b=par[i+(1<<k-1)][k-1];
		if(depth[a]<depth[b])	par[i][k]=a;
		else	par[i][k]=b;
	}
	M=readInt();
	while(M--){
		a=readInt();b=readInt();
		int c, t=1, p=0, ans, x, y;
		if(in[a]<in[b])	x=in[a], y=in[b];
		else	x=in[b], y=in[a];
		c=y-x+1;
		while(t*2<=c)	t*=2, ++p;
		y=y-t+1;
		x=par[x][p], y=par[y][p];
		if(depth[x]<depth[y])	ans=x;
		else	ans=y;
		printf("%d\n", ans);
	}
	return 0;
}
