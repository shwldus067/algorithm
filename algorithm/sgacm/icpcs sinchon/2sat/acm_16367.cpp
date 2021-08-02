#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int K, N, dfsn[10001], sccn[10001], idx=1, ord=1;
vector<int> adj[10001];
stack<int> st;
char color[5001];
int dfs(int cur){
	int ret=dfsn[cur]=ord++;
	st.push(cur);
	for(int n:adj[cur]){
		if(dfsn[n]==0)	ret=min(ret, dfs(n));
		else if(sccn[n]==0)	ret=min(ret, dfsn[n]);
	}
	if(ret==dfsn[cur]){
		int v;
		do{
			v=st.top();
			st.pop();
			sccn[v]=idx;
		}while(v!=cur);
		idx++;
	}
	return ret;
}
int f(int x, char c){
	if(c=='R'){
		return x-1;
	}
	else{
		return K+x-1;
	}
}
int g(int x){
	return x>=K ? x-K:K+x;
}
int main(){
	scanf("%d %d", &K, &N);
	while(N--){
		int x, y, z;
		char a, b, c;
		scanf("%d %c %d %c %d %c", &x, &a, &y, &b, &z, &c);
		x=f(x, a);
		y=f(y, b);
		z=f(z, c);
		adj[g(x)].push_back(y);
		adj[g(x)].push_back(z);
		adj[g(y)].push_back(x);
		adj[g(y)].push_back(z);
		adj[g(z)].push_back(x);
		adj[g(z)].push_back(y);
	}
	for(int i=0;i<2*K;++i){
		if(dfsn[i]==0)	dfs(i);
	}
	for(int i=0;i<K;++i){
		if(sccn[i]==sccn[i+K]){
			printf("-1\n");
			return 0;
		}
		color[i]=(sccn[i]<sccn[i+K] ? 'R':'B');
	}
	printf("%s\n", color);
	return 0;
}
