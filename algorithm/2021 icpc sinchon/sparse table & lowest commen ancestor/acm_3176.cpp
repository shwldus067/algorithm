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
int par[100001][18], depth[100001], mind[100001][18], maxd[100001][18];
int ansm, ansM;
vector<pii> adj[100001];
void dfs(int u, int v, int d, int dist){
	par[v][0]=u;
	mind[v][0]=maxd[v][0]=dist;
	depth[v]=d;
	for(pii &n:adj[v]){
		if(n.first==u)	continue;
		dfs(v, n.first, d+1, n.second);
	}
}
void lca(int u, int v){
	if(depth[u]<depth[v])	swap(u, v);
	ansm=ansM=mind[u][0];
	int t=depth[u]-depth[v];
	for(int k=0;k<18;++k)if(t&(1<<k))
		ansm=min(ansm, mind[u][k]), ansM=max(ansM, maxd[u][k]), u=par[u][k];
	if(u==v)	return;
	for(int k=17;k>=0;--k){
		if(par[u][k]!=par[v][k]){
			ansm=min(ansm, mind[u][k]), ansM=max(ansM, maxd[u][k]);
			u=par[u][k];
			ansm=min(ansm, mind[v][k]), ansM=max(ansM, maxd[v][k]);
			v=par[v][k];
		}
	}
	ansm=min(ansm, min(mind[v][0], mind[u][0]));
	ansM=max(ansM, max(maxd[v][0], maxd[u][0]));
}
int main(){
	int N, K, a, b, c;
	N=readInt();
	for(int i=1;i<N;++i){
		a=readInt();b=readInt();c=readInt();
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	fill(&mind[0][0], &mind[N][18], 1e7);
	dfs(0, 1, 0, 0);
	mind[1][0]=1e7;
	for(int k=1;k<18;++k)for(int i=1;i<=N;++i){
		par[i][k]=par[par[i][k-1]][k-1];
		int t=par[i][k-1];
		if(t>1){
			mind[i][k]=min(mind[i][k-1], mind[t][k-1]);
			maxd[i][k]=max(maxd[i][k-1], maxd[t][k-1]);
		}
	}
	K=readInt();
	while(K--){
		a=readInt();b=readInt();
		lca(a, b);
		printf("%d %d\n", ansm, ansM);
	}
	return 0;
}
