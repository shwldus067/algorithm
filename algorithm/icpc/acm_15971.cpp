#include<iostream>
#include<queue>
using namespace std;
typedef pair<int, int> pii;
int N, A, B, disA[100001];
vector<pii>	adj[100001];
void distance(){
	bool visit[100001]={0, };
	queue<int> Q;
	Q.push(A);
	visit[A]=1;
	while(Q.size()){
		int cur=Q.front();Q.pop();
		for(pii p:adj[cur]){
			if(visit[p.first])	continue;
			disA[p.first]=disA[cur]+p.second;
			visit[p.first]=1;
			Q.push(p.first);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y, z;
	cin>>N>>A>>B;
	for(int i=1;i<N;++i){
		cin>>x>>y>>z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	distance();
	queue<pii> qu;
	qu.push({B, 0});
	int ans=disA[B];
	bool chk[100001]={0, };
	chk[B]=1;
	while(qu.size()){
		pii cur=qu.front();qu.pop();
		for(pii p:adj[cur.first]){
			if(chk[p.first])	continue;
			ans=min(ans, cur.second+disA[p.first]);
			if(ans<=cur.second+p.second)	continue;
			chk[p.first]=1;
			qu.push({p.first, cur.second+p.second});
		}
	}
	cout<<ans<<"\n";
	return 0;
}
