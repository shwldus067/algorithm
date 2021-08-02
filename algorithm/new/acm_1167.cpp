#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int point;
bool visit[100001];
vector<pair<int, int> > adj[100001];

int dfs(int v){
	int res=0, i, f, s, j, k;
	stack<pair<int, int> > S;
	
	S.push({v, 0});
	visit[v]=true;
	while(!S.empty()){
		f=S.top().first;
		s=S.top().second;
		for(i=0;i<adj[f].size();i++){
			if(!visit[adj[f][i].first]){
				j=adj[f][i].first;
				k=adj[f][i].second;
				S.push({j, k+s});
				visit[j]=true;
				if(res<k+s){
					res=k+s;
					point=j;
				}
				break;
			}
		}
		if(i==adj[f].size())	S.pop();
	}
	return res;
}

int main(){
	int v, V, id, ver, len, res;
	
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
	res=dfs(1);
	fill(&visit[0], &visit[V+1], false);
	res=dfs(point);
	
	cout<<res<<"\n";
}
