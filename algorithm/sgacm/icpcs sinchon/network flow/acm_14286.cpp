#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M, c[501][501], f[501][501], s, t;
vector<int> adj[501];
int bfs(){
	int res=0;
	while(1){
		vector<int> p(501, -1);
		queue<int> Q;
		Q.push(s);
		while(Q.size() && p[t]==-1){
			int cur=Q.front();
			Q.pop();
			for(int n:adj[cur]){
				if(p[n]!=-1)	continue;
				if(c[cur][n]-f[cur][n]<=0)	continue;
				p[n]=cur;
				Q.push(n);
				if(n==t)	break;
			}
		}
		if(p[t]==-1)	break;
		int minv=1e6;
		for(int x=t;x!=s;x=p[x]){
			minv=min(minv, c[p[x]][x]-f[p[x]][x]);
		}
		for(int x=t;x!=s;x=p[x]){
			f[p[x]][x]+=minv;
			f[x][p[x]]-=minv;
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
		adj[x].push_back(y);
		adj[y].push_back(x);
		c[x][y]=c[y][x]=z;
	}
	cin>>s>>t;
	cout<<bfs()<<"\n";
	return 0;
}
