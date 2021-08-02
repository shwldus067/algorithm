#include<stdio.h>
int main(){
	int N, M, T, A[51][51], B[51];
	bool del[51][51];
	scanf("%d %d %d", &N, &M, &T);
	for(int i=0;i<=N;++i){
		B[i]=0;
		for(int j=0;j<=N;++j){
			A[i][j]=0, del[i][j]=0;
		}
	}
	for(int i=1;i<=N;++i)for(int j=1;j<=M;++j)	scanf("%d", &A[i][j]);
	while(T--){
		int x, d, k;
		scanf("%d %d %d", &x, &d, &k);
		for(int i=x;i<=N;i+=x){
			if(d)	B[i]=(B[i]+k)%M;
			else	B[i]=(B[i]+M-k)%M;
		}
		int f=0;
		for(int i=1;i<=N;++i)for(int j=0;j<M;++j){
			int c=(B[i]+j)%M+1, t=A[i][c];
			if(t==0)	continue;
			if(t==A[i][c>1?c-1:M] || t==A[i][c<M ? c+1:1] || (i>1 && t==A[i-1][(B[i-1]+j)%M+1]) || (i<N && t==A[i+1][(B[i+1]+j)%M+1]))
				del[i][c]=1, f=1;
		}
		if(f){
			for(int i=1;i<=N;++i)for(int j=1;j<=M;++j){
				if(del[i][j]){
					A[i][j]=0, del[i][j]=0;
				}
			}
		}
		else{
			int sum=0, cnt=0;
			for(int i=1;i<=N;++i)for(int j=1;j<=M;++j){
				if(A[i][j])	sum+=A[i][j], cnt++;
			}
			if(cnt==0)	break;
			int m=sum/cnt, r=sum%cnt;
			for(int i=1;i<=N;++i)for(int j=1;j<=M;++j){
				if(A[i][j]==0)	continue;
				if(A[i][j]<m)	A[i][j]++;
				else if(A[i][j]>m)	A[i][j]--;
				else if(r)	A[i][j]++;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=N;++i)for(int j=1;j<=M;++j) ans+=A[i][j];
	printf("%d\n", ans);
	return 0;
}
