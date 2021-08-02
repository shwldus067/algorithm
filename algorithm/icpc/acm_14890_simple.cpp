#include<stdio.h>
int main(){
	int N, L, ans=0, M, i, j, c;
	short A[200][100];
	scanf("%d %d", &N, &L);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%hd", &A[i][j]);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	A[i+N][j]=A[j][i];
	M=2*N;
	for(i=0;i<M;++i){
		c=1;
		for(j=0;j<N-1;++j){
			if(A[i][j]==A[i][j+1])	++c;
			else if(A[i][j]+1==A[i][j+1] && c>=L)	c=1;
			else if(A[i][j]-1==A[i][j+1] && c>=0)	c=-L+1;
			else	break;
		}
		if(j==N-1 && c>=0)	++ans;
	}
	printf("%d\n", ans);
	return 0;
}
