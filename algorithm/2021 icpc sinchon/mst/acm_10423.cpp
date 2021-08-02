#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct str{
	int u, v, w;
	bool operator<(const str a)const{
		return w<a.w;
	}
};
bool chk[1001];
vector<pair<int, int> > adj[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, u, v, w;
	int p[1000];
	cin>>N>>M>>K;
	priority_queue<str> pq;
	for(int i=0;i<K;++i)	cin>>p[i], chk[p[i]]=1;
	while(M--){
		cin>>u>>v>>w;
		adj[u].push_back({v, w});
		adj[v].push_back({u, w});
	}
	for(int i=0;i<K;++i){
		u=p[i];
		for(pair<int, int> &nxt:adj[u]){
			pq.push({u, nxt.first, -nxt.second});
		}
	}
	int ans=0;
	while(pq.size()){
		str cur=pq.top();pq.pop();
		if(chk[cur.v])	continue;
		chk[cur.v]=true;
		ans-=cur.w;
		u=cur.v;
		for(pair<int, int> &nxt:adj[u]){
			if(chk[nxt.first])	continue;
			pq.push({u, nxt.first, -nxt.second});
		}
	}
	cout<<ans<<"\n";
	return 0;
}
