#include<stdio.h>
int N, K, A[12][12], B[12][12][3];
int dr[4]={0, 0, -1, 1}, dc[4]={1, -1, 0, 0};
struct hr{
	int x, y, d, n;
}H[11];
int main(){
	scanf("%d %d", &N, &K);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%d", &A[i][j]);
	for(int i=1;i<=K;++i){
		int x, y, d;
		scanf("%d %d %d", &x, &y, &d);
		--x, --y;
		H[i]={x, y, d-1, 0};
		B[x][y][0]=i;
	}
	int ans=1, f, idx, num, tmp, chg;
	while(ans<=1000){
		f=0;
		for(int i=1;i<=K;++i){
			int d=H[i].d, x=H[i].x, y=H[i].y, n=H[i].n;
			int r=x+dr[d], c=y+dc[d];
			if(B[x][y][2])	num=3;
			else if(B[x][y][1])	num=2;
			else	num=1;
			num-=n;
			if(r<0 || r>=N || c<0 || c>=N || A[r][c]==2){
				if(d&1)	--d;
				else	++d;
				r=x+dr[d], c=y+dc[d];
				H[i].d=d;
			}
			if(r<0 || r>=N || c<0 || c>=N || A[r][c]==2)	continue;
			else{
				if(B[r][c][3-num]){
					f=1;break;
				}
				if(B[r][c][1])	idx=2;
				else if(B[r][c][0])	idx=1;
				else	idx=0;
				for(int k=0;k<num;++k){
					tmp=B[r][c][idx+k]=B[x][y][n+k];
					B[x][y][n+k]=0;
					H[tmp].x=r, H[tmp].y=c, H[tmp].n=idx+k;
				}
				if(A[r][c] && num>1){
					if(num==2)	chg=1;
					else if(num==3)	chg=2;
					tmp=B[r][c][idx];
					H[B[r][c][idx+chg]].n=idx;
					B[r][c][idx]=B[r][c][idx+chg];
					B[r][c][idx+chg]=tmp;
					H[tmp].n=idx+chg;
				}
			}
		}
		if(f)	break;
		ans++;
	}
	if(f)	printf("%d\n", ans);
	else	printf("-1\n");
	return 0;
}
