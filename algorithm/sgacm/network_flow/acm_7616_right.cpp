#include<stdio.h>
#include<vector>
using namespace std;
struct node{
	int x, y, z=0;	//x=num, y=capacity, z=flow;
	int dual;	//dual=next;
	node(int _x, int _y) : x(_x), y(_y){}
};
int N, K;
vector<node> adj[10001], v;
bool visit[10001];
void splitv(int x){
	int i=adj[x].size(), j=adj[x+N].size();
	adj[x].push_back({x+N, 1});
	adj[x+N].push_back({x, 0});
	adj[x][i].dual=j;
	adj[x+N][j].dual=i;
}
void addnode(int x, int y){
	if(x>2)	x+=N;
	int i=adj[x].size(), j=adj[y].size();
	adj[x].push_back({y, 1});
	adj[y].push_back({x, 0});
	adj[x][i].dual=j;
	adj[y][j].dual=i;
}
int dfs(int cur){
	int i;
	visit[cur]=true;
	if(cur==2)	return 1;
	for(i=0;i<adj[cur].size();i++){
		node &itr=adj[cur][i];
		if(visit[itr.x] || itr.y==itr.z)	continue;
		v.push_back({cur, i});
		if(dfs(itr.x))	return 1;
		v.pop_back();
	}
	return 0;
}
int maxflow(){
	int res=0;
	while(1){
		int i, mn=~(1<<31);
		v.clear();
		for(i=1;i<=N*2;i++)	visit[i]=false;
		if(res==K || !dfs(1))	return res;
		for(i=0;i<v.size();i++){
			node itr=v[i];
			node &n=adj[itr.x][itr.y];
			mn=min(mn, n.y-n.z);
		}
		for(i=0;i<v.size();i++){
			node itr=v[i];
			adj[itr.x][itr.y].z+=mn;
			adj[adj[itr.x][itr.y].x][adj[itr.x][itr.y].dual].z-=mn;
		}
		res+=mn;
	}
}
void print(int cur){
	if(cur==2){
		printf("2\n");
		return;
	}
	int i;
	for(i=0;i<adj[cur].size();i++){
		if(!adj[cur][i].y || !adj[cur][i].z)	continue;
		if(cur<=N)	printf("%d ", cur);
		print(adj[cur][i].x);
	}
}
int main(){
	int i, n, tc=1;
	char t;
	while(1){
		scanf("%d %d", &K, &N);
		if(K==0 && N==0)	break;
		for(i=3;i<=N;i++)	splitv(i);
		for(i=1;i<=N;i++){
			while(1){
				scanf("%d%c", &n, &t);
				if(n<i){
					if(t=='\n')	break;
					continue;
				}
				addnode(i, n);
				addnode(n, i);
				if(t=='\n')	break;
			}
		}
		int ans=maxflow();
		printf("Case %d:\n", tc++);
		if(ans<K)	printf("Impossible\n");
		else	print(1);
		printf("\n");
		for(i=1;i<=N*2;i++)	adj[i].clear();
	}
	return 0;
}
