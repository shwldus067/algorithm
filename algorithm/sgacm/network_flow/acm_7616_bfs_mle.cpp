#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int n, c, f=0, idx;
	node(int _n, int _c, int _idx):n(_n), c(_c), idx(_idx){}
};
int K, N, res, tc=1;
vector<node> adj[10001];
void print(int cur){
	if(cur==3){
		printf("2\n");
		return;
	}
	for(int i=0;i<adj[cur].size();i++){
		node x=adj[cur][i];
		if(!x.c || !x.f)	continue;
		if(!(cur&1))	printf("%d ", cur/2);
		print(x.n);
	}
}
int main(){
	while(1){
		scanf("%d %d", &K, &N);
		if(K==0 && N==0)	break;
		res=0;
		vector<int> path;
		int a, b;
		for(int i=1;i<=N;i++){
			int n;
			char t;
			while(1){
				scanf("%d%c", &n, &t);
				a=adj[i*2].size(), b=adj[n*2-1].size();
				adj[i*2].push_back({n*2-1, 1, b});
				adj[n*2-1].push_back({i*2, 0, a});
				if(t=='\n')	break;
			}
		}
		a=adj[1].size(), b=adj[2].size();
		adj[1].push_back({2, 1, b});
		adj[1][a].f=1;
		adj[2].push_back({1, 0, a});
		a=adj[3].size(), b=adj[4].size();
		adj[3].push_back({4, 1, b});
		adj[3][b].f=1;
		adj[4].push_back({3, 0, a});
		for(int i=3;i<=N;i++){
			adj[2*i-1].push_back({2*i, 1, adj[2*i-1].size()});
			adj[2*i].push_back({2*i-1, 0, adj[2*i].size()});
		}
		int p[N*2+1][2];
		while(1){
			fill(&p[0][0], &p[2*N][2], -1);
			queue<int> Q;
			Q.push(2);
			while(!Q.empty() && p[3][0]==-1){
				int cur=Q.front();
				Q.pop();
				for(int v=0;v<adj[cur].size();v++){
					node next=adj[cur][v];
					if(p[next.n][0]!=-1)	continue;
					if(next.c-next.f<=0) continue;
					p[next.n][0]=cur;
					p[next.n][1]=v;
					Q.push(next.n);
					if(next.n==3)	break;
				}
			}
			if(p[3][0]==-1)	break;
			for(int x=3;x!=2;x=p[x][0]){
				int a=p[x][0], b=p[x][1];
				adj[a][b].f+=1;
				adj[x][adj[a][b].idx].f-=1;
			}
			res++;
			if(res==K)	break;
		}
		printf("Case %d:\n", tc++);
		if(res==K){
			print(2);
			printf("\n");
		}
		else{
			printf("Impossible\n\n");
		}
		for(int i=1;i<=N*2;i++)	adj[i].clear();
	}
	return 0;
}
