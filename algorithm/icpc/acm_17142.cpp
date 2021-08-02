#include<stdio.h>
int N, M, K, A[50][50], idx, ans=10000, v[10];
int dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
struct vir{
	int r, c;
}virus[10];
void bfs(){
	int visit[50][50]={0, }, s=0, e=0;
	vir Q[2500];
	for(int i=0;i<M;++i){
		Q[e++]=virus[v[i]];
		visit[virus[v[i]].r][virus[v[i]].c]=1;
	}
	int size, time=0, num=0;
	while(size=e-s){
		if(num==K)	break;
		while(size--){
			int r=Q[s].r, c=Q[s].c;
			++s;
			for(int d=0;d<4;++d){
				int nr=r+dr[d], nc=c+dc[d];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(A[nr][nc]==1 || visit[nr][nc])	continue;
				if(A[nr][nc]==0)	num++;
				visit[nr][nc]=1;
				Q[e++]={nr, nc};
			}
		}
		++time;
	}
	if(num<K)	return;
	if(ans>time)	ans=time;
}
void dfs(int k, int cnt){
	if(cnt==M){
		bfs();
		return;
	}
	if(idx-k<M-cnt)	return;
	for(int i=k;i<idx;++i){
		v[cnt]=i;
		dfs(i+1, cnt+1);
	}
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		scanf("%d", &A[i][j]);
		if(A[i][j]==2){
			virus[idx++]={i, j};
		}
		else if(A[i][j]==0)	++K;
	}
	dfs(0, 0);
	if(ans==10000)	printf("-1\n");
	else	printf("%d\n", ans);
	return 0;
}
