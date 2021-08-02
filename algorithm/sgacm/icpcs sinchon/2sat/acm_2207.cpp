#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N, M, dfsn[20001], sccn[20001], idx=1, ord=1;
vector<int> adj[20001];
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
			sccn[v]=ord;
		}while(v!=cur);
		ord++;
	}
	return ret;
}
int f(int x){
	return x<0 ? M-x:x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		int x, y;
		cin>>x>>y;
		adj[f(-x)].push_back(f(y));
		adj[f(-y)].push_back(f(x));
	}
	for(int i=1;i<=M*2;++i){
		if(!dfsn[i])	dfs(i);
	}
	for(int i=1;i<=M;++i){
		if(sccn[i]==sccn[i+M]){
			cout<<"OTL"<<"\n";
			return 0;
		}
	}
	cout<<"^_^\n";
	return 0;
}
