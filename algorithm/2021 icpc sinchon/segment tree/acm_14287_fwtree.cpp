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
int N, M, cnt, in[100000], out[100000], fw[200001];
vector<int> adj[100000];
void dfs(int u){
	in[u]=++cnt;
	for(int v:adj[u])	dfs(v);
	out[u]=++cnt;
}
void update(int i, int d){
	while(i<cnt){
		fw[i]+=d;
		i+=i&(-i);
	}
}
int query(int i){
	int ret=0;
	while(i){
		ret+=fw[i];
		i-=i&(-i);
	}
	return ret;
}
int main(){
	N=readInt();M=readInt();
	int t, a, b;
	for(int i=0;i<N;++i){
		t=readInt();
		if(t>0)	adj[t-1].push_back(i);
	}
	dfs(0);
	++cnt;
	while(M--){
		t=readInt();
		if(t==1){
			a=readInt();b=readInt();
			update(in[a-1], b);
		}else{
			a=readInt();
			--a;
			printf("%d\n", query(out[a])-query(in[a]-1));
		}
	}
	return 0;
}
