#include<iostream>
#include<vector>
using namespace std;
int point, res=0;
bool visit[100001];
vector<pair<int, int> > adj[100001];

void dfs(int v, int cost){
	if(visit[v])	return;
	visit[v]=true;
	if(res<cost){
		res=cost;
		point=v;
	}
	for(int i=0;i<adj[v].size();i++){
		dfs(adj[v][i].first, cost+adj[v][i].second);
	}
}

int main(){
	int v, V, id, ver, len;
	
	cin>>V;
	for(v=0;v<V;v++){
		cin>>id;
		cin>>ver;
		while(ver!=-1){
			cin>>len;
			adj[id].push_back({ver, len});
			cin>>ver;
		}
	}
	fill(&visit[0], &visit[V+1], false);
	dfs(1, 0);
	fill(&visit[0], &visit[V+1], false);
	dfs(point, 0);
	
	cout<<res<<"\n";
}
