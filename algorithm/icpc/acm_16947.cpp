#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, res[3001], check[3001];
vector<int> adj[3001];
queue<int> Q;
int func(int cur, int pre){
	if(check[cur]==1)	return cur;
	check[cur]=1;
	for(int i=0;i<adj[cur].size();i++){
		int next=adj[cur][i];
		if(next==pre)	continue;
		int res=func(next, cur);
		if(res==-2)	return -2;
		if(res>0){
			check[cur]=2;
			if(cur==res)	return -2;
			else return res;
		}
	}
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	func(1, 0);
	for(int i=1;i<=N;i++){
		if(check[i]==2)	Q.push(i);
		else	res[i]=-1;
	}
	while(!Q.empty()){
		int u=Q.front();
		Q.pop();
		for(int i=0;i<adj[u].size();i++){
			int v=adj[u][i];
			if(res[v]==-1){
				Q.push(v);
				res[v]=res[u]+1;
			}
		}
	}
	for(int i=1;i<=N;i++)	cout<<res[i]<<' ';
	cout<<"\n";
	return 0;
}
