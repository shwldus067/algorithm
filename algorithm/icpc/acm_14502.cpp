#include<stdio.h>
int N, M, arr[8][8], idx, ans;
int dr[4]={0, 0, -1, 1}, dc[4]={-1, 1, 0, 0};
int dr2[8]={-1, -1, 0, 1, 1, 1, 0, -1};
int dc2[8]={0, 1, 1, 1, 0, -1, -1, -1};
struct pii{
	int first, second;
};
pii virus[10];
void sol(){
	pii Q[65];
	int s, e;
	s=e=0;
	int visit[8][8]={0, };
	for(int i=0;i<idx;++i)	Q[e++]=virus[i];
	while(s<e){
		int cr=Q[s].first, cc=Q[s++].second;
		for(int i=0;i<4;++i){
			int nr=cr+dr[i], nc=cc+dc[i];
			if(nr<0 || nr>=N || nc<0 || nc>=M)	continue;
			if(arr[nr][nc] || visit[nr][nc])	continue;
			visit[nr][nc]=1;
			Q[e++]={nr, nc};
		}
	}
	int sum=0;
	for(int i=0;i<N;++i){
		for(int j=0;j<M;++j){
			if(!arr[i][j] && !visit[i][j]){
				++sum;
			}
		}
	}
	if(ans<sum)	ans=sum;
}
void dfs(int cnt, int r, int c){
	if(cnt>2){
		sol();
		return;
	}
	if(r==N)	return;
	int f=0;
	if(!arr[r][c]){
		for(int i=0;i<8;++i){
			int nr=r+dr2[i], nc=c+dc2[i];
			if(nr<0 || nr>=N || nc<0 || nc>=M || arr[nr][nc]){
				f=1;break;
			}
		}
		if(f){
			arr[r][c]=1;
			if(c==M-1)	dfs(cnt+1, r+1, 0);
			else	dfs(cnt+1, r, c+1);
			arr[r][c]=0;
		}
	}
	if(c==M-1)	dfs(cnt, r+1, 0);
	else	dfs(cnt, r, c+1);
}
int main(){
	scanf("%d %d", &N, &M);
	for(int i=0;i<N;++i)for(int j=0;j<M;++j){
		scanf("%d", &arr[i][j]);
		if(arr[i][j]==2){
			virus[idx++]={i, j};
		}
	}
	dfs(0, 0, 0);
	printf("%d\n", ans);
	return 0;
}
