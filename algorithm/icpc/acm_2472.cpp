#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int N, A[3], M, T, Q, val;
vector<pair<int, int> > adj[100001];
struct node{
	int n, d[3];
	bool operator<(const node &Node){
		if(d[0]==Node.d[0]){
			if(d[1]==Node.d[1])	return d[2]>Node.d[2];
			return d[1]>Node.d[1];
		}
		return d[0]<Node.d[0];
	}
}store[100001];
pair<int, int> B[100001];
int tree[100001], L;
bool chk[100001];
void bfs(int idx){
	priority_queue<pair<int, int> > qu;
	store[A[idx]].d[idx]=0;
	qu.push({0, A[idx]});
	while(qu.size()){
		int cur=qu.top().second, cost=qu.top().first;
		qu.pop();
		if(store[cur].d[idx]<-cost) continue;
		for(pair<int, int> &nxt:adj[cur]){
			if(store[nxt.first].d[idx]<=-cost+nxt.second)	continue;
			store[nxt.first].d[idx]=-cost+nxt.second;
			qu.push({cost-nxt.second, nxt.first});
		}
	}
}
void update(int i, int d){
	while(i<=L){
		tree[i]=min(tree[i], d);
		i+=(i&-i);
	}
}
int query(int i){
	int ret=1e9;
	while(i){
		ret=min(ret, tree[i]);
		i-=(i&-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>A[0]>>A[1]>>A[2]>>M;
	while(M--){
		int x, y, z;
		cin>>x>>y>>z;
		adj[x].push_back({y, z});
		adj[y].push_back({x, z});
	}
	for(int i=1;i<=N;++i)	store[i].n=i, store[i].d[0]=store[i].d[1]=store[i].d[2]=1e9;
	bfs(0);bfs(1);bfs(2);
	sort(store+1, store+N+1);
	for(int i=1;i<=N;++i)	B[i]={store[i].d[1], i};
	sort(B+1, B+N+1);
	int pre=-1;
	for(int i=1;i<=N;++i){
		if(pre<B[i].first)	pre=B[i].first, ++L;
		store[B[i].second].d[1]=L;
	}
	for(int i=1;i<=L;++i)	tree[i]=1e9;
	for(int i=1;i<=N;++i){
		int x=store[i].d[1];
		if(query(x-1)<store[i].d[2])	chk[store[i].n]=1;
		update(x, store[i].d[2]);
	}
	cin>>T;
	while(T--){
		cin>>Q;
		if(chk[Q])	cout<<"NO\n";
		else	cout<<"YES\n";
	}
	return 0;
}
