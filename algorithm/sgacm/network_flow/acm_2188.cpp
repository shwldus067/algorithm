#include<stdio.h>
#include<vector>
using namespace std;
int N, M;
bool visit[201];
vector<int> cow[201];
int from[201];
bool dfs(int cur){
	if(visit[cur])	return false;
	visit[cur]=true;
	vector<int>::iterator next;
	for(next=cow[cur].begin();next<cow[cur].end();next++){
		if(from[*next]==-1 || dfs(from[*next])){
			from[*next]=cur;
			return true;
		}
	}
	return false;
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=1;i<=N;i++){
		int s;
		scanf("%d", &s);
		for(int j=0;j<s;j++){
			int t;
			scanf("%d", &t);
			cow[i].push_back(t);
		}
	}
	int res=0;
	fill(from, from+M+1, -1);
	for(int i=1;i<=N;i++){
		fill(visit, visit+N+1, false);
		if(dfs(i))	res++;
	}
	printf("%d\n", res);
	return 0;
}
