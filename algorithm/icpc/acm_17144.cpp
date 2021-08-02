#include<stdio.h>
int main(){
	int R, C, T, A[2][50][50], idx=0;
	int air[2];
	scanf("%d %d %d", &R, &C, &T);
	for(int i=0;i<R;++i)for(int j=0;j<C;++j){
		scanf("%d", &A[0][i][j]);
		if(A[0][i][j]<0)	air[idx++]=i;
	}
	int t=0, p=1;
	while(T--){
		for(int i=0;i<R;++i)for(int j=0;j<C;++j)	A[p][i][j]=0;
		A[p][air[0]][0]=A[p][air[1]][0]=-1;
		for(int i=0;i<R;++i)for(int j=0;j<C;++j){
			if(A[t][i][j]>0){
				int k=A[t][i][j], m=k/5;
				if(i>0 && A[t][i-1][j]>=0)	A[p][i-1][j]+=m, k-=m;
				if(j>0 && A[t][i][j-1]>=0)	A[p][i][j-1]+=m, k-=m;
				if(i<R-1 && A[t][i+1][j]>=0) A[p][i+1][j]+=m, k-=m;
				if(j<C-1 && A[t][i][j+1]>=0) A[p][i][j+1]+=m, k-=m;
				A[p][i][j]+=k;
			}
		}
		t=p, p^=1;
		for(int i=air[0]-1;i;--i)	A[t][i][0]=A[t][i-1][0];
		for(int i=1;i<C;++i)	A[t][0][i-1]=A[t][0][i];
		for(int i=0;i<air[0];++i)	A[t][i][C-1]=A[t][i+1][C-1];
		for(int i=C-2;i;--i)	A[t][air[0]][i+1]=A[t][air[0]][i];
		A[t][air[0]][1]=0;
		for(int i=air[1]+2;i<R;++i)	A[t][i-1][0]=A[t][i][0];
		for(int i=1;i<C;++i)	A[t][R-1][i-1]=A[t][R-1][i];
		for(int i=R-1;i>air[1];--i)	A[t][i][C-1]=A[t][i-1][C-1];
		for(int i=C-2;i;--i)	A[t][air[1]][i+1]=A[t][air[1]][i];
		A[t][air[1]][1]=0;
	}
	int ans=0;
	for(int i=0;i<R;++i)for(int j=0;j<C;++j)	ans+=A[t][i][j];
	printf("%d\n", ans+2);
	return 0;
}
