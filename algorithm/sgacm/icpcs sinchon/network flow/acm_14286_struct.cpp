#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, s, t;
struct edge_{
	int x, c;
	edge_* rev;
}edge[20000];
vector<edge_*> adj[501];
int bfs(){
	int res=0;
	while(1){
		int p[501]={0, };
		queue<int> Q;
		edge_* path[501];
		Q.push(s);
		while(Q.size() && !p[t]){
			int cur=Q.front();
			Q.pop();
			for(edge_* n:adj[cur]){
				if(p[n->x])	continue;
				if(n->c<=0)	continue;
				p[n->x]=cur;
				path[n->x]=n;
				Q.push(n->x);
				if(n->x==t)	break;
			}
		}
		if(!p[t])	break;
		int minv=1e6;
		for(int x=t;x!=s;x=p[x]){
			minv=min(minv, path[x]->c);
		}
		for(int x=t;x!=s;x=p[x]){
			path[x]->c-=minv;
			path[x]->rev->c+=minv;
		}
		res+=minv;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	while(M--){
		int x, y, z;
		cin>>x>>y>>z;
		int k=M*2;
		edge[k]={y, z, &edge[k+1]};
		edge[k+1]={x, z, &edge[k]};
		adj[x].push_back(&edge[k]);
		adj[y].push_back(&edge[k+1]);
	}
	cin>>s>>t;
	cout<<bfs()<<"\n";
	return 0;
}
