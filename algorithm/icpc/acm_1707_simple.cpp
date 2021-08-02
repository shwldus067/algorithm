#include<cstdio>
using namespace std;
#define max(u, v) u>v?u:v
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
	bool f=0;
	char cur=read();
	while(cur!='-' && (cur==10 || cur==32))	cur=read();
	if(cur=='-')	f=1, cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	if(f)	sum=-sum;
	return sum;
}
int des[20001], par[20001];
int find(int u){
	while(par[u]!=u){
		u=par[u]=par[par[u]];
	}
	return u;
}
int merge(int u, int v){
	if(u==-1 || v==-1)	return max(u, v);
	u=find(u), v=find(v);
	if(u==v)	return u;
	par[u]=v;
	return v;
}
bool dfs(int u, int v){
	u=find(u), v=find(v);
	if(u==v)	return false;
	int a=merge(u, des[v]), b=merge(v, des[u]);
	des[a]=b;
	des[b]=a;
	return true;
}
int main(){
	int K, V, E, a, b, f;
	K=readInt();
	while(K--){
		V=readInt();E=readInt();
		for(int i=1;i<=V;++i)	des[i]=-1, par[i]=i;
		f=0;
		while(E--){
			a=readInt();b=readInt();
			if(f)	continue;
			else if(!dfs(a, b))	f=1;
		}
		if(f)	printf("NO\n");
		else	printf("YES\n");
	}
	return 0;
}
