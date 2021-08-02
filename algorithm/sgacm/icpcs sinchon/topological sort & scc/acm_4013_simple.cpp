#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
int N, M, S, P, ord=1, idx=1;
int dfsn[500001], sccn[500001], val[500001], sval[500001];
vector<int> adj[500001];
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
			sval[idx]+=val[v];
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
	for(int i=1;i<=N;++i){
		if(dfsn[i]==0)	dfs(i);
	}
	bool res[idx]={0, };
	cin>>S>>P;
	while(P--){
		int a;
		cin>>a;
		res[sccn[a]]=1;
	}
	int start=sccn[S];
	vector<vector<int> > adjd(idx);
	for(int i=1;i<=N;++i){
		if(sccn[i]==0)	continue;
		for(int n:adj[i]){
			if(sccn[n]==0)	continue;
			if(sccn[i]!=sccn[n])
				adjd[sccn[i]].push_back(sccn[n]);
		}
	}
	int ans=0;
	vector<int> dp(idx, 0);
	queue<int> Q;
	dp[start]=sval[start];
	Q.push(start);
	if(res[start])	ans=dp[start];
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		for(int v:adjd[cur]){
			if(dp[v]<sval[v]+dp[cur]){
				dp[v]=sval[v]+dp[cur];
				if(res[v]){
					ans=max(ans, dp[v]);
				}
				Q.push(v);
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
