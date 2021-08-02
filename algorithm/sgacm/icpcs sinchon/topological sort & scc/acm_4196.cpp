#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int T, N, M;
vector<int> adj[100000];
stack<int> S;
int dfsn[100000], sccn[100000], indegree[100000];
int ord, idx;
int dfs(int cur){
	int res=dfsn[cur]=ord++;
	S.push(cur);
	for(int next:adj[cur]){
		if(dfsn[next]==-1)
			res=min(res, dfs(next));
		else if(sccn[next]==-1)
			res=min(res, dfsn[next]);
	}
	if(res==dfsn[cur]){
		int v;
		do{
			v=S.top();
			S.pop();
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
	cin>>T;
	while(T--){
		cin>>N>>M;
		for(int i=0;i<N;++i)	adj[i]=vector<int>();
		fill(dfsn, dfsn+N, -1);
		fill(sccn, sccn+N, -1);
		fill(indegree, indegree+N, 0);
		ord=idx=0;
		while(M--){
			int a, b;
			cin>>a>>b;
			adj[a-1].push_back(b-1);
		}
		for(int i=0;i<N;++i){
			if(dfsn[i]==-1)	dfs(i);
		}
		for(int i=0;i<N;++i){
			for(int j:adj[i]){
				if(sccn[i]!=sccn[j])
					indegree[sccn[j]]++;
			}
		}
		int ans=0;
		for(int i=0;i<idx;++i){
			if(indegree[i]==0)	ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
