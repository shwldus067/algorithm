#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N, M, dfsn[5001], sccn[5001], idx, ord;
bool chk[5001];
vector<int> adj[5001];
stack<int> S;
int dfs(int cur){
	int ret=dfsn[cur]=ord++;
	S.push(cur);
	for(int n:adj[cur]){
		if(dfsn[n]==0)	ret=min(ret, dfs(n));
		else if(sccn[n]==0)	ret=min(ret, dfsn[n]);
	}
	if(ret==dfsn[cur]){
		int v;
		do{
			v=S.top();
			S.pop();
			sccn[v]=idx;
		}while(v!=cur);
		idx++;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
		cin>>N;
		if(N==0)	break;
		cin>>M;
		idx=ord=1;
		for(int i=1;i<=N;++i){
			adj[i]=vector<int>();
			dfsn[i]=sccn[i]=0;
			chk[i]=true;
		}
		while(M--){
			int a, b;
			cin>>a>>b;
			adj[a].push_back(b);
		}
		for(int i=1;i<=N;++i){
			if(dfsn[i]==0)	dfs(i);
		}
		for(int i=1;i<=N;++i){
			for(int n:adj[i]){
				if(sccn[i]!=sccn[n]){
					chk[sccn[i]]=false;
				}
			}
		}
		for(int i=1;i<=N;++i){
			if(chk[sccn[i]]){
				cout<<i<<' ';
			}
		}
		cout<<'\n';
	}
	return 0;
}
