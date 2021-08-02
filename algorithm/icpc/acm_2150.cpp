#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
int V, E, K;
vector<int> adj[10001];
vector<int> radj[10001];
vector<vector<int> > SCC;
bool visit[10001];
stack<int> S;
bool cmp(vector<int> &a, vector<int> &b){
	return a[0]<b[0];
}
void dfs(int v){
	visit[v]=1;
	for(int  n:adj[v]){
		if(visit[n])	continue;
		dfs(n);
	}
	S.push(v);
}
void rdfs(int v, int c){
	visit[v]=1;
	SCC[c].push_back(v);
	for(int n:radj[v]){
		if(visit[n])	continue;
		rdfs(n, c);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>V>>E;
	int A, B;
	while(E--){
		cin>>A>>B;
		adj[A].push_back(B);
		radj[B].push_back(A);
	}
	for(int i=1;i<=V;++i){
		if(visit[i])	continue;
		dfs(i);
	}
	for(int i=1;i<=V;++i)	visit[i]=0;
	while(S.size()){
		int cur=S.top();
		S.pop();
		if(visit[cur])	continue;
		SCC.resize(++K);
		rdfs(cur, K-1);
	}
	for(int i=0;i<K;++i)	sort(SCC[i].begin(), SCC[i].end());
	sort(SCC.begin(), SCC.end(), cmp);
	cout<<K<<"\n";
	for(int i=0;i<K;++i){
		for(int x:SCC[i])	cout<<x<<" ";
		cout<<"-1\n";
	}
	return 0;
}
