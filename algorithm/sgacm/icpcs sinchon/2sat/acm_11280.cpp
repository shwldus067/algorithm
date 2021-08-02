#include<iostream>
#include<vector>
#include<stack>
using namespace std;
typedef vector<int> vi;
int N, M, sccn[20002], dfsn[20002], ord=1, idx=1;
vi adj[20002];
stack<int> st;
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
int f(int a){
	return a>N ? a-N:a+N;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		if(a<0)	a=-a+N;
		if(b<0)	b=-b+N;
		adj[f(a)].push_back(b);
		adj[f(b)].push_back(a);
	}
	for(int i=1;i<=2*N;++i){
		if(!dfsn[i])	dfs(i);
	}
	for(int i=1;i<=N;++i){
		if(sccn[i]==sccn[i+N]){
			cout<<"0\n";
			return 0;
		}
	}
	cout<<"1\n";
	return 0;
}
