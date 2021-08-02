#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int N, P, s=1, t=2, res=0;
int parent[401];
queue<int> Q;
vector<int> adj[401];
void bfs(){
	while(1){
		fill(parent, parent+N+1, -1);
		Q.push(s);
		while(!Q.empty()){
			int cur=Q.front();
			Q.pop();
			for(int v=0;v<adj[cur].size();v++){
				int next=adj[cur][v];
				if(parent[next]!=-1)	continue;
				parent[next]=cur;
				Q.push(next);
			}
		}
		if(parent[t]==-1)	break;
		for(int x=t;x!=s;x=parent[x]){
			adj[x].push_back(parent[x]);	//reverse path
			vector<int>::iterator it;
			it=remove(adj[parent[x]].begin(), adj[parent[x]].end(), x);	//한번 간 길은 다른 경로에 포함되지 않음
			adj[parent[x]].erase(it, adj[parent[x]].end());	//위에서 x값들을 뒤로 다 보내고 첫 x값을 갖는 위치 return받아 erase
		}
		res++;
	}
}
int main(){
	scanf("%d %d", &N, &P);
	int u, v;
	for(int i=0;i<P;i++){
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
	}
	bfs();
	printf("%d\n", res);
	return 0;
}
