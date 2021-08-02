#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N, M, ord=1, idx=1;
int dfsn[40], sccn[40];
vector<int> adj[40];
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
int f(int x){
	return x<0 ? N-x-1:x-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		adj[f(-a)].push_back(f(b));
		adj[f(-b)].push_back(f(a));
	}
	for(int i=0;i<2*N;++i){
		if(dfsn[i]==0)	dfs(i);
	}
	for(int i=0;i<N;++i){
		if(sccn[i]==sccn[i+N]){
			cout<<"0\n";
			return 0;
		}
	}
	cout<<"1\n";
	for(int i=0;i<N;++i){
		cout<<(sccn[i]<sccn[i+N])<<" ";
	}
	return 0;
}
