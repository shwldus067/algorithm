#include<cstdio>
#include<vector>
using namespace std;
int V, E, dfsn[10001], low[10001], ord, k;
bool ap[10001];
vector<int> adj[10001];
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
void dfs(int u, int v){
	dfsn[v]=low[v]=++ord;
	int child=0;
	for(int n:adj[v]){
		if(!dfsn[n]){
			child++;
			dfs(v, n);
			if(!u && child>1)	ap[v]=1;
			else if(u && low[n]>=dfsn[v])	ap[v]=1;
			low[v]=min(low[v], low[n]);
		}
		else	low[v]=min(low[v], dfsn[n]);
	}
	if(ap[v])	++k;
}
int main(){
	V=readInt();E=readInt();
	int A, B;
	while(E--){
		A=readInt();B=readInt();
		adj[A].push_back(B);
		adj[B].push_back(A);
	}
	for(int i=1;i<=V;++i)if(!dfsn[i])	dfs(0, i);
	printf("%d\n", k);
	for(int i=1;i<=V;++i)if(ap[i])	printf("%d ", i);
	return 0;
}
