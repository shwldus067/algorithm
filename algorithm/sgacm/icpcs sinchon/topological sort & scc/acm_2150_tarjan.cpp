#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
int V, E, dfsn[10001], sccn[10001], idx=1, ord=1;
stack<int> S;
vector<int> adj[10001];
vector<vector<int> > SCC;
int dfs(int cur){
	S.push(cur);
	int res=dfsn[cur]=++ord;
	for(int n:adj[cur]){
		if(dfsn[n]==0)	res=min(res, dfs(n));
		else if(sccn[n]==0)	res=min(res, dfsn[n]);
	}
	if(res==dfsn[cur]){
		vector<int> C;
		int v;
		do{
			v=S.top();
			S.pop();
			sccn[v]=idx;
			C.push_back(v);
		}while(v!=cur);
		sort(C.begin(), C.end());
		SCC.push_back(C);
		idx++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>V>>E;
	while(E--){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
	}
	for(int i=1;i<=V;++i){
		if(dfsn[i]==0)
			dfs(i);
	}
	sort(SCC.begin(), SCC.end());
	cout<<idx-1<<"\n";
	for(int i=0;i<idx-1;++i){
		for(int n:SCC[i]){
			cout<<n<<" ";
		}
		cout<<"-1\n";
	}
	return 0;
}
