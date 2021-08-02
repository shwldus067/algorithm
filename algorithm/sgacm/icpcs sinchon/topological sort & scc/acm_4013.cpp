#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N, M, S, P, ord=1, idx=1;
int dfsn[500001], sccn[500001], val[500001], dp[500001], sval[500001];
vector<int> adj[500001];
vector<int> adjd[500001];
vector<int> res;
stack<int> st;
int dfs(int cur){
	int res=dfsn[cur]=ord++;
	st.push(cur);
	for(int n:adj[cur]){
		if(dfsn[n]==0)	res=min(res, dfs(n));
		else if(sccn[n]==0)	res=min(res, dfsn[n]);
	}
	if(res==dfsn[cur]){
		int v;
		do{
			v=st.top();
			st.pop();
			sccn[v]=idx;
		}while(v!=cur);
		idx++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=1;i<=N;++i){
		cin>>val[i];
	}
	cin>>S>>P;
	for(int i=0;i<P;++i){
		int a;
		cin>>a;
		res.push_back(a);
	}
	dfs(S);
	for(int i=1;i<=N;++i){
		if(sccn[i]==0)	continue;
		for(int n:adj[i]){
			if(sccn[n]==0)	continue;
			if(sccn[i]!=sccn[n])
				adjd[sccn[i]].push_back(sccn[n]);
		}
	}
	for(int i=1;i<=N;++i){
		if(sccn[i]==0)	continue;
		sval[sccn[i]]+=val[i];
	}
	int ans=0;
	for(int i=idx-1;i>0;--i){
		dp[i]+=sval[i];
		for(int n:adjd[i]){
			dp[n]=max(dp[n], dp[i]);
		}
	}
	for(int v:res){
		if(sccn[v]==0)	continue;
		ans=max(ans, dp[sccn[v]]);
	}
	cout<<ans<<"\n";
	return 0;
}
