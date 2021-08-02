#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N, M, dfsn[40000], sccn[40000], idx, ord;
vector<int> adj[40000];
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
	return x<0 ? M-x-1:x-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
		cin>>N>>M;
		if(N==0 && M==0)	return 0;
		for(int i=0;i<2*M;++i){
			adj[i].clear();
			dfsn[i]=sccn[i]=0;
		}
		idx=ord=1;
		for(int i=0;i<N;++i){
			int x, y;
			cin>>x>>y;
			adj[f(x)].push_back(f(-y));
			adj[f(y)].push_back(f(-x));
		}
		for(int i=0;i<2*M;++i){
			if(dfsn[i]==0)	dfs(i);
		}
		bool chk=true;
		for(int i=0;i<M;++i){
			if(sccn[i]==sccn[i+M]){
				cout<<"0\n";
				chk=false;
				break;
			}
		}
		if(chk)	cout<<"1\n";
	}
	return 0;
}
