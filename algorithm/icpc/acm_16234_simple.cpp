#include<cstdio>
#include<cstring>
typedef struct point{
	int x, y;
}point;
int N, L, R, A[52][52], top, val, cnt, st_s;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, 1, 0, -1};
bool visit[52][52];
point S[2500], st[2500];
void dfs(int x, int y){
	if(visit[x][y])	return;
	visit[x][y]=1;
	S[top++]={x, y};
	val+=A[x][y];
	for(int d=0;d<4;++d){
		int nx=x+dx[d], ny=y+dy[d], gap=A[nx][ny]-A[x][y];
		gap=gap<0?-gap:gap;
		if(A[nx][ny]!=-1 && !visit[nx][ny] && L<=gap && gap<=R)
			dfs(nx, ny);
	}
	if(top>1 && x==S[0].x && y==S[0].y){
		val/=top;
		for(int i=0;i<top;++i){
			A[S[i].x][S[i].y]=val;
			st[st_s++]={S[i].x, S[i].y};
		}
		cnt=1;
	}
}
int main(){
	scanf("%d %d %d", &N, &L, &R);
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j)	scanf("%d", &A[i][j]);
	for(int i=0;i<=N;++i){
		A[0][i]=A[i][0]=A[N+1][i]=A[i][N+1]=-1;
	}
	for(int i=1;i<=N;++i){
		for(int j=(i&1)+1;j<=N;j+=2){
			dfs(i, j);
			top=0, val=0;
		}
	}
	int ans=0;
	point tmp_st[2500];
	for(;cnt;++ans){
		memset(visit, 0, sizeof(visit));
		cnt=0;
		memcpy(tmp_st, st, sizeof(point)*st_s);
		int tmp=st_s;
		st_s=0;
		for(int i=0;i<tmp;++i){
			dfs(tmp_st[i].x, tmp_st[i].y);
			top=0, val=0;
		}
	}
	printf("%d\n", ans);
	return 0;
}
