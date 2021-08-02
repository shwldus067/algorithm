#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
char buf[1<<17];
inline char read(){
	static int idx=1<<17;
	if(idx==1<<17){
		fread(buf, 1, 1<<17, stdin);
		idx=0;
	}
	return buf[idx++];
}
inline int readInt(){
	int sum=0;
	bool f=0;
	char cur=read();
	while(cur!='-' && (cur==10 || cur==32))	cur=read();
	if(cur=='-')	f=1, cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	if(f)	sum=-sum;
	return sum;
}
struct edge{
	int x, c;
	edge *r;
	edge(int x, int c):x(x), c(c){}
	void add_f(int new_f){
		c-=new_f;
		r->c+=new_f;
	}
};
int N;
int lv[301], work[301];
vector<edge*> adj[301], Eg;
bool bfs(){
	memset(lv, 0, sizeof(lv));
	lv[1]=1;
	queue<int> Q;
	Q.push(1);
	while(Q.size()){
		int cur=Q.front();
		Q.pop();
		for(edge *nxt:adj[cur]){
			int x=nxt->x;
			if(!lv[x] && nxt->c>0){
				lv[x]=lv[cur]+1;
				Q.push(x);
			}
		}
	}
	return lv[N]!=0;
}
int dfs(int x, int flow){
	if(x==N)	return flow;
	for(int &i=work[x];i<adj[x].size();++i){
		edge *nxt=adj[x][i];
		if(lv[nxt->x]==lv[x]+1 && nxt->c>0){
			int min_flow=dfs(nxt->x, min(flow, nxt->c));
			if(min_flow){
				nxt->add_f(min_flow);
				return min_flow;
			}
		}
	}
	return 0;
}
int rev_flow(void){
	int ret=0;
	int parent[301];
	for(edge *E:Eg){
		if(E->c!=0)	continue;
		int s=E->r->x, t=E->x;
		memset(parent, 0, sizeof(parent));
		queue<int> Q;
		Q.push(s);
		while(Q.size() && !parent[t]){
			int cur=Q.front();Q.pop();
			for(edge *nxt:adj[cur]){
				int x=nxt->x;
				if(!parent[x] && nxt->c>0){
					parent[x]=cur;
					Q.push(x);
					if(x==t)	break;
				}
			}
		}
		if(!parent[t])	ret++;
	}
	return ret;
}
int main(){
	int K, M, u, v, b;
	K=readInt();
	while(K--){
		N=readInt();M=readInt();
		while(M--){
			u=readInt();v=readInt();b=readInt();
			edge *e1=new edge(v, b);
			edge *e2=new edge(u, 0);
			e1->r=e2;
			e2->r=e1;
			adj[u].push_back(e1);
			adj[v].push_back(e2);
			Eg.push_back(e1);
		}
		while(bfs()){
			memset(work, 0, sizeof(work));
			while(dfs(1, 100000));
		}		
		printf("%d\n", rev_flow());
		for(int i=1;i<=N;++i)	adj[i].clear();
		Eg.clear();
	}
	return 0;
}
