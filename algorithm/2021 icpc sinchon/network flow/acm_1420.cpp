#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct edge{
	int x, c, f;
	edge *r;
	edge(int x, int c):x(x), c(c), f(0){}
	int residual(){return c-f;}
	void add_flow(void){
		f++;
		r->f--;
	}
};
int N, M;
char arr[100][101];
vector<edge*> adj[20000];
void make_edge(int u, int v, int c1, int c2){
	edge *e1=new edge(v, c1);
	edge *e2=new edge(u, c2);
	e1->r=e2;
	e2->r=e1;
	adj[u].push_back(e1);
	adj[v].push_back(e2);
}
inline int pos(int i, int j){
	return 0<=i && i<N && 0<=j && j<M && arr[i][j]!='#';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int S, E, sr, sc, er, ec;
	int dr[4]={-1, 0, 0, 1}, dc[4]={0, 1, -1, 0};
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		for(int j=0;j<M;++j){
			if(arr[i][j]=='K')	S=i*100+j+10000, sr=i, sc=j;
			else if(arr[i][j]=='H')	E=i*100+j, er=i, ec=j;
			else if(arr[i][j]=='#')	continue;
			int k=i*100+j;
			make_edge(k, k+10000, 1, 0);
			for(int d=0;d<4;++d){
				int r=i+dr[d], c=j+dc[d];
				if(pos(r, c)){
					int t=r*100+c;
					make_edge(k+10000, t, (int)1e9, 0);
				}
			}
		}
	}
	for(int i=0;i<4;++i){
		if(sr+dr[i]==er && sc+dc[i]==ec){
			cout<<"-1\n";
			return 0;
		}
	}
	int ans=0, pr[20000];
	edge *pe[20000];
	while(1){
		queue<int> Q;
		fill(pr, pr+20000, -1);
		Q.push(S);
		while(Q.size() && pr[E]==-1){
			int cur=Q.front();Q.pop();
			for(edge *nxt:adj[cur]){
				int x=nxt->x;
				if(pr[x]==-1 && nxt->residual()>0){
					pr[x]=cur;
					pe[x]=nxt;
					Q.push(x);
					if(pr[E]!=-1)	break;
				}
			}
		}
		if(pr[E]==-1)	break;
		for(int i=E;i!=S;i=pr[i])
			pe[i]->add_flow();
		++ans;
	}
	cout<<ans<<"\n";
	return 0;
}
