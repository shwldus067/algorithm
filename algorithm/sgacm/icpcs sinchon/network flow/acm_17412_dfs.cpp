#include<iostream>
#include<vector>
using namespace std;
const int inf=~(1<<31);
int N, P, s=1, t=2;
int c[401][401], f[401][401];
bool visit[401];
vector<int> adj[401];
int dfs(int a){
	if(visit[a])	return 0;
	visit[a]=true;
	if(a==t)	return 1;
	for(int b:adj[a]){
		int cur=c[a][b]-f[a][b];
		if(cur<=0)	continue;
		int res=dfs(b);
		if(res){
			f[a][b]+=1;
			f[b][a]-=1;
			return 1;
		}
	}
	return 0;
}
int maxflow(){
	int res=0;
	while(1){
		fill(visit, visit+401, false);
		int flow=dfs(1);
		if(!flow)	break;
		res++;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P;
	for(int i=0;i<P;++i){
		int a, b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b]=1;
	}
	cout<<maxflow()<<"\n";
	return 0;
}
