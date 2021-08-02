#include<cstdio>
int N, M, x, y, K, A[20][20], dice[4][3];
int dx[5]={0, 0, 0, -1, 1}, dy[5]={0, 1, -1, 0, 0};
int main(){
	scanf("%d %d %d %d %d", &N, &M, &x, &y, &K);
	for(int i=0;i<N;++i)for(int j=0;j<M;++j) scanf("%d", &A[i][j]);
	while(K--){
		int d, t;
		scanf("%d", &d);
		x+=dx[d], y+=dy[d];
		if(x<0 || x>=N || y<0 || y>=M){
			x-=dx[d], y-=dy[d];
			continue;
		}
		if(d==1){
			t=dice[1][0];
			dice[1][0]=dice[3][1];
			dice[3][1]=dice[1][2];
			dice[1][2]=dice[1][1];
			dice[1][1]=t;
		}else if(d==2){
			t=dice[1][0];
			dice[1][0]=dice[1][1];
			dice[1][1]=dice[1][2];
			dice[1][2]=dice[3][1];
			dice[3][1]=t;
		}else if(d==3){
			t=dice[0][1];
			dice[0][1]=dice[1][1];
			dice[1][1]=dice[2][1];
			dice[2][1]=dice[3][1];
			dice[3][1]=t;
		}else{
			t=dice[0][1];
			dice[0][1]=dice[3][1];
			dice[3][1]=dice[2][1];
			dice[2][1]=dice[1][1];
			dice[1][1]=t;
		}
		if(A[x][y])	dice[3][1]=A[x][y], A[x][y]=0;
		else	A[x][y]=dice[3][1];
		printf("%d\n", dice[1][1]);
	}
	return 0;
}
