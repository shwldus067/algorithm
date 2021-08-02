#include<stdio.h>
int main(){
	int N, M, x, y, K, A[20][20], dice[6]={0, }, tmp[6];
	int dx[4]={0, 0, -1, 1}, dy[5]={1, -1, 0, 0};
	int chg[4][6]={{3, 1, 0, 5, 4, 2}, {2, 1, 5, 0, 4, 3},
	{4, 0, 2, 3, 5, 1}, {1, 5, 2, 3, 0, 4}};
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for(int i=0;i<N;++i)for(int j=0;j<M;++j) scanf("%d", &A[i][j]);
	while(K--){
		int d, t;
		scanf("%d", &d);
		--d;
		x+=dx[d], y+=dy[d];
		if(x<0 || x>=N || y<0 || y>=M){
			x-=dx[d], y-=dy[d];continue;
		}
		for(int i=0;i<6;++i)	tmp[i]=dice[chg[d][i]];
		for(int i=0;i<6;++i)	dice[i]=tmp[i];
		if(A[x][y])	dice[5]=A[x][y], A[x][y]=0;
		else	A[x][y]=dice[5];
		printf("%d\n", dice[0]);
	}
	return 0;
}
