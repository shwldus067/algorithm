#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int N, M;
int dfsn[2001], sccn[2001], idx=1, ord=1;
vector<int> adj[2001];
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
	while(cin>>N){
		cin>>M;
		for(int i=0;i<N*2;++i)	adj[i].clear(), dfsn[i]=sccn[i]=0;
		idx=ord=1;
		stack<int> emp;
		swap(st, emp);
		for(int i=0;i<M;++i){
			int a, b;
			cin>>a>>b;
			adj[f(-a)].push_back(f(b));
			adj[f(-b)].push_back(f(a));
		}
		adj[N].push_back(0);
		for(int i=0;i<N*2;++i){
			if(!dfsn[i])	dfs(i);
		}
		bool f=false;
		for(int i=0;i<N;++i){
			if(sccn[i]==sccn[N+i]){
				f=true;
				break;
			}
		}
		if(f)	cout<<"no\n";
		else	cout<<"yes\n";
	}
}
