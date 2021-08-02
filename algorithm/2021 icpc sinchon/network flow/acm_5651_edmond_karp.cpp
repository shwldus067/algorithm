#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct edge{
	int x, c;
	edge *r;
	edge(int x, int c):x(x), c(c), r(0){}
	void add_f(int new_f){
		c-=new_f;
		r->c+=new_f;
	}
};
int N;
vector<int> lv, work;
vector<edge*> adj[301], Eg;
void bfs(){
	while(1){
		vector<int> pre(N+1, -1);
		edge *path[N+1]={0, };
		queue<int> Q;
		Q.push(1);
		while(Q.size() && pre[N]==-1){
			int cur=Q.front();Q.pop();
			for(edge *nxt:adj[cur]){
				int x=nxt->x;
				if(pre[x]!=-1)	continue;
				if(nxt->c>0){
					Q.push(x);
					pre[x]=cur;
					path[x]=nxt;
					if(x==N)	break;
				}
			}
		}
		if(pre[N]==-1)	break;
		int mflow=100000;
		for(int i=N;i!=1;i=pre[i])	mflow=min(mflow, path[i]->c);
		for(int i=N;i!=1;i=pre[i])	path[i]->add_f(mflow);
	}
}
int rev_flow(void){
	int ret=0;
	vector<int> parent;
	for(edge *E:Eg){
		if(E->c!=0)	continue;
		int s=E->r->x, t=E->x;
		parent.assign(N+1, -1);
		queue<int> Q;
		Q.push(s);
		while(Q.size() && parent[t]==-1){
			int cur=Q.front();Q.pop();
			for(edge *nxt:adj[cur]){
				int x=nxt->x;
				if(parent[x]==-1 && nxt->c>0){
					parent[x]=cur;
					Q.push(x);
					if(x==t)	break;
				}
			}
		}
		if(parent[t]==-1)	ret++;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, M, u, v, b;
	cin>>K;
	while(K--){
		int flow=0;
		cin>>N>>M;
		while(M--){
			cin>>u>>v>>b;
			edge *e1=new edge(v, b);
			edge *e2=new edge(u, 0);
			e1->r=e2;
			e2->r=e1;
			adj[u].push_back(e1);
			adj[v].push_back(e2);
			Eg.push_back(e1);
		}
		bfs();
		cout<<rev_flow()<<"\n";
		for(int i=1;i<=N;++i)	adj[i].clear();
		Eg.clear();
	}
	return 0;
}
