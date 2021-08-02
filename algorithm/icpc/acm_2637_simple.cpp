#include<cstdio>
#include<vector>
using namespace std;
char ind[100], idx[100];
int ans[100];
int main(){
	int nxt[100][100], cost[100][100];
	int N, M, X, Y, K;
	char Q[100], l=0, r=1;
	scanf("%d %d", &N, &M);
	while(M--){
		scanf("%d %d %d", &X, &Y, &K);
		--X, --Y;
		nxt[X][idx[X]]=Y;
		cost[X][idx[X]++]=K;
		++ind[Y];
	}
	Q[0]=N-1;
	ans[N-1]=1;
	while(l<r){
		int cur=Q[l++];
		for(int i=0;i<idx[cur];++i){
			ans[nxt[cur][i]]+=cost[cur][i]*ans[cur];
			if(--ind[nxt[cur][i]]==0)	Q[r++]=nxt[cur][i];
		}
	}
	for(int i=0;i<N;++i){
		if(idx[i]==0)	printf("%d %d\n", i+1, ans[i]);
	}
	return 0;
}
