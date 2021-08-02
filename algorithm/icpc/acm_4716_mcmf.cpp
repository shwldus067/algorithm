#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
struct edge{
	int v, cap, cost, rev, flow;
	edge(int v, int cap, int cost, int rev, int flow):
		v(v), cap(cap), cost(cost), rev(rev), flow(flow){}
};
int N, A, B, S, T, p[1005], idx[1005];
vector<vector<edge> > adj;
void addedge(int u, int v, int cap, int cost){
	adj[u].push_back(edge(v, cap, cost, adj[v].size(), 0));
	adj[v].push_back(edge(u, 0, -cost, adj[u].size()-1, 0));
}
bool spfa(){
	vector<int> dist(1005, 1e9);
	vector<int> inq(1005, 0);
	queue<int> Q;
	Q.push(S);dist[S]=0, inq[S]=1;
	while(Q.size()){
		int cur=Q.front();Q.pop();
		inq[cur]=0;
		for(int i=0;i<adj[cur].size();++i){
			int nxt=adj[cur][i].v;
			int cost=adj[cur][i].cost;
			int cap=adj[cur][i].cap;
			if(cap && dist[nxt]>dist[cur]+cost){
				dist[nxt]=dist[cur]+cost;
				p[nxt]=cur;idx[nxt]=i;
				if(!inq[nxt]){
					inq[nxt]=1;
					Q.push(nxt);
				}
			}
		}
	}
	return dist[T]!=1e9;
}
int sol(){
	int ret=0;
	while(spfa()){
		int f=1e9;
		for(int i=T;i!=S;i=p[i]){
			f=min(f, adj[p[i]][idx[i]].cap);
		}
		for(int i=T;i!=S;i=p[i]){
			int prv=p[i], pidx=idx[i];
			adj[prv][pidx].cap-=f;
			adj[prv][pidx].flow+=f;
			adj[i][adj[prv][pidx].rev].cap+=f;
			adj[i][adj[prv][pidx].rev].flow-=f;
			ret+=f*adj[prv][pidx].cost;
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	while(1){
		cin>>N>>A>>B;
		if(!N)	break;
		T=N+3;
		memset(idx, 0, sizeof(idx));
		memset(p, 0, sizeof(p));
		adj.clear();
		adj.resize(N+4);
		addedge(0, N+1, A, 0), addedge(0, N+2, B, 0);
		for(int i=1;i<=N;++i){
			int k, da, db;
			cin>>k>>da>>db;
			addedge(N+1, i, k, da);
			addedge(N+2, i, k, db);
			addedge(i, T, k, 0);
		}
		cout<<sol()<<"\n";
	}
	return 0;
}
