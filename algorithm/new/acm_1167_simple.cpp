#include<iostream>
#include<vector>
using namespace std;
int V, res;
vector<pair<int, int> > adj[100001];
int dfs(int s, int p){
	int first=0, second=0, sum=0;
	for(int i=adj[s].size()-1;i>=0;--i){
		if(adj[s][i].first==p)	continue;
		sum=dfs(adj[s][i].first, s)+adj[s][i].second;
		if(sum>first){
			second=first;
			first=sum;
		}
		else if(sum>second){
			second=sum;
		}
	}
	if(res<(first+second))	res=first+second;
	return first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>V;
	int id, ver, len;
	for(int v=0;v<V;v++){
		cin>>id;
		cin>>ver;
		while(ver!=-1){
			cin>>len;
			adj[id].push_back({ver, len});
			cin>>ver;
		}
	}
	dfs(1, 0);
	cout<<res<<"\n";
}
