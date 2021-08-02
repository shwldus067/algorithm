#include<stdio.h>
#include<string.h>
short N, M, A[10][10], ans=64, K;
short dir[5][4][4]={{{0},{1},{2},{3}},
			{{0,2},{1,3}},
			{{0,1},{1,2},{2,3},{3,0}},
			{{0,1,2},{1,2,3},{2,3,0},{3,0,1}},
			{{0,1,2,3}}};
short fs[5]={4, 2, 4, 4, 1}, sc[5]={1, 2, 2, 3, 4};
short cctv[8][2], cctvn[8], idx;
short dr[4]={-1, 0, 1, 0}, dc[4]={0, 1, 0, -1};
bool chk[9][10][10];
void sol(short n, short sum){
	if(n==idx){
		if(sum<ans)	ans=sum;
		return;
	}
	int t=cctvn[n];
	for(int i=0;i<fs[t];++i){
		memcpy(chk[n+1], chk[n], 100);
		short x=0;
		for(int j=0;j<sc[t];++j){
			short d=dir[t][i][j];
			for(short r=cctv[n][0], c=cctv[n][1];A[r][c]!=6;r+=dr[d], c+=dc[d]){
				if(!chk[n+1][r][c]){
					chk[n+1][r][c]=1;
					++x;
				}
			}
		}
		sol(n+1, sum-x);
	}
}
int main(){
	scanf("%hi %hi", &N, &M);
	for(int i=0;i<M+2;++i){
		A[0][i]=A[N+1][i]=6;
	}
	for(int i=1;i<=N;++i){
		A[i][0]=A[i][M+1]=6;
		for(int j=1;j<=M;++j){
			scanf("%hi", &A[i][j]);
			if(A[i][j]==6)	++K;
			else if(A[i][j]){
				cctvn[idx]=A[i][j]-1;
				cctv[idx][0]=i, cctv[idx][1]=j;
				++idx;
			}
		}
	}
	sol(0, N*M-K);
	printf("%hi\n", ans);
	return 0;
}
