#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
int N, M, e[1001];
vector<int> F[1001];
bool visit[1001];
void bfs(int u){
	queue<int> Q;
	Q.push(u);
	visit[u]=1;
	while(Q.size()){
		int v=Q.front();Q.pop();
		for(int nv:F[v]){
			if(!visit[nv]){
				visit[nv]=1;
				Q.push(nv);
			}
		}
	}
}
int main(){
	scanf("%d%d", &N, &M);
	while(M--){
		char r, t;
		int a, b;
		scanf("%c%c%d%d", &t, &r, &a, &b);
		if(r=='E'){
			if(!e[a])	e[a]=b;
			if(!e[b])	e[b]=a;
			F[e[a]].push_back(b);
			F[e[b]].push_back(a);
			F[b].push_back(e[a]);
			F[a].push_back(e[b]);
		}else{
			F[a].push_back(b);
			F[b].push_back(a);
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i){
		if(!visit[i]){
			bfs(i);
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
