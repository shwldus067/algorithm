#include<stdio.h>
struct dir{
	int x, y;
};
int N, M, K, A[20][20], R, C, rr, cc;
int dr[4]={-1, 0, 0, 1}, dc[4]={0, -1, 1, 0};
dir D[402];
int bfs(int x){
	if(!x && A[R][C])	return 0;
	bool visit[20][20]={0, };
	visit[R][C]=1;
	dir Q[400];
	Q[0]={R, C};
	int s=0, e=1, ret=0, f=0, tmp=1;
	while(1){
		++ret;
		for(int i=s;i<e;++i){
			for(int k=0;k<4;++k){
				int nr=Q[i].x+dr[k], nc=Q[i].y+dc[k];
				if(nr<0 || nr>=N || nc<0 || nc>=N)	continue;
				if(A[nr][nc]==1 || visit[nr][nc])	continue;
				if(!x && A[nr][nc]){
					if(!f)	R=nr, C=nc;
					f=true;
					if(nr<R)	R=nr, C=nc;
					else if(nr==R && nc<C)	R=nr, C=nc;
				}else if(x && nr==rr && nc==cc){
					A[R][C]=0;
					R=nr, C=nc;
					return ret;
				}
				visit[nr][nc]=1;
				Q[tmp++]={nr, nc};
			}
		}
		if(f)	return ret;
		s=e, e=tmp;
		if(s==e)	return -1;
	}
}
int main(){
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%d", &A[i][j]);
	scanf("%d %d", &R, &C);
	R--, C--;
	for(int i=1;i<=M;){
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A[a-1][b-1]=++i;
		D[i]={c-1, d-1};
	}
	while(M--){
		int dis=bfs(0);
		if(dis<0){
			printf("-1\n");
			return 0;
		}
		K-=dis;
		int idx=A[R][C];
		rr=D[idx].x, cc=D[idx].y;
		dis=bfs(1);
		if(K<dis || dis<0){
			printf("-1\n");
			return 0;
		}
		K+=dis;
	}
	printf("%d\n", K);
	return 0;
}
