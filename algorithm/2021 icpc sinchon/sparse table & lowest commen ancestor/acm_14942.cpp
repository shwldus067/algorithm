#include<iostream>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
vector<pii>	adj[100001];
int arr[17][100001], p[17][100001];
void dfs(int u, int v){
	for(pii &nxt:adj[v]){
		int x=nxt.first;
		if(x==u)	continue;
		arr[0][x]=nxt.second;
		p[0][x]=v;
		dfs(v, x);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, A[100001], a, b, c;
	cin>>N;
	++N;
	for(int i=1;i<N;++i)	cin>>A[i];
	for(int i=2;i<N;++i){
		cin>>a>>b>>c;
		adj[a].push_back({b, c});
		adj[b].push_back({a, c});
	}
	p[0][1]=1;
	dfs(0, 1);
	for(int k=1;k<17;++k){
		int t=k-1;
		for(int i=1;i<N;++i){
			arr[k][i]=arr[t][i]+arr[t][p[t][i]];
			p[k][i]=p[t][p[t][i]];
		}
	}
	for(int i=1;i<N;++i){
		int x=i;
		for(int k=16;k>=0;--k){
			if(A[i]>=arr[k][x])	A[i]-=arr[k][x], x=p[k][x];
		}
		cout<<x<<"\n";
	}
	return 0;
}
