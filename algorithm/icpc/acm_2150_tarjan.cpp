#include<cstdio>
#include<vector>
#include<algorithm>
#include<stack>
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
int V, E, dfsn[10001], K, ord;
bool scch[10001];
stack<int> S;
vector<int> adj[10001];
vector<vector<int> > SCC;
bool cmp(vector<int> &a, vector<int> &b){return a[0]<b[0];};
int dfs(int v){
	S.push(v);
	int ret=dfsn[v]=++ord;
	for(int n:adj[v]){
		if(!dfsn[n])	ret=min(ret, dfs(n));
		else if(!scch[n])	ret=min(ret, dfsn[n]);
	}
	if(ret==dfsn[v]){
		vector<int> C;
		int u;
		do{
			u=S.top();S.pop();
			scch[u]=1;
			C.push_back(u);
		}while(u!=v);
		sort(C.begin(), C.end());
		SCC.push_back(C);
		++K;
	}
	return ret;
}
int main(){
	V=readInt();E=readInt();
	int a, b;
	while(E--){
		a=readInt();b=readInt();
		adj[a].push_back(b);
	}
	for(int i=1;i<=V;++i)if(!dfsn[i])	dfs(i);
	sort(SCC.begin(), SCC.end(), cmp);
	printf("%d\n", K);
	for(int i=0;i<K;++i){
		for(int n:SCC[i])	printf("%d ", n);
		printf("-1\n");
	}
	return 0;
}
