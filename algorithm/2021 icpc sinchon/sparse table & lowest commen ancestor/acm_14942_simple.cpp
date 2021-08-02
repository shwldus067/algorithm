#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii>	adj[100001];
vector<int> st;
int A[100001], C[100001];
void dfs(int u, int v){
	st.push_back(v);
	int l=0, r=int(st.size())-1;
	while(l<=r){
		int m=(l+r)>>1;
		if(A[v]<C[v]-C[st[m]])	l=m+1;
		else	r=m-1;
	}
	A[v]=st[l];
	for(pii &nxt:adj[v]){
		int x=nxt.first;
		if(x==u)	continue;
		C[x]=nxt.second+C[v];
		dfs(v, x);
	}
	st.pop_back();
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, a, b, c;
	cin>>N;
	++N;
	for(int i=1;i<N;++i)	cin>>A[i];
	for(int i=2;i<N;++i){
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	dfs(0, 1);
	for(int i=1;i<N;++i)	cout<<A[i]<<"\n";
	return 0;
}
