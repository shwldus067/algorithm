#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
int V, E, cnt;
bool visit[10001];
vector<int> adj[10001];
vector<int> radj[10001];
vector<vector<int> > SCC;
stack<int> S;
bool cmp(vector<int> a, vector<int> b){
	return a[0]<b[0];
}
void dfs(int v){
	visit[v]=1;
	for(int n:adj[v]){
		if(visit[n])
			continue;
		dfs(n);
	}
	S.push(v);
}
void func(int v, int c){
	visit[v]=1;
	SCC[c].push_back(v);
	for(int n:radj[v]){
		if(visit[n])
			continue;
		func(n, c);
	}
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
		radj[b].push_back(a);
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
		SCC.resize(++cnt);
		func(cur, cnt-1);
	}
	for(int i=0;i<cnt;++i){
		sort(SCC[i].begin(), SCC[i].end());
	}
	sort(SCC.begin(), SCC.end(), cmp);
	cout<<cnt<<"\n";
	for(int i=0;i<cnt;++i){
		for(int x:SCC[i]){
			cout<<x<<" ";
		}
		cout<<"-1\n";
	}
	return 0;
}
