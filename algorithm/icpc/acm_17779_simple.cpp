#include<stdio.h>
inline int min(int a, int b){
	return a<b?a:b;
}
inline int max(int a, int b){
	return a>b?a:b;
}
int N, A[20][20], sum, ans;
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		scanf("%d", &A[i][0]);
		for(int j=1;j<N;++j){
			scanf("%d", &A[i][j]);
			A[i][j]+=A[i][j-1];
		}
		sum+=A[i][N-1];
	}
	ans=sum;
	for(int d1=1;d1<N-1;++d1){
		for(int d2=1;d2+d1<N;++d2){
			for(int x=0;x+d1+d2<N;++x){
				for(int y=d1;y+d2<N;++y){
					int a=0, b=0, c=0, d=0, e=0;
					for(int i=0;i<x;++i){
						a+=A[i][y];
						b+=A[i][N-1]-A[i][y];
					}
					for(int i=x+d1+d2+1;i<N;++i){
						c+=A[i][y-d1+d2-1];
						d+=A[i][N-1]-A[i][y-d1+d2-1];
					}
					for(int i=0;i<d1 || i<=d2;++i){
						if(i<d1)	a+=A[x+i][y-i-1];
						if(i<=d2)	b+=A[x+i][N-1]-A[x+i][y+i];
					}
					for(int i=0;i<=d2;++i)	c+=A[x+d1+i][y-d1+i-1];
					for(int i=1;i<=d1;++i)	d+=A[x+d2+i][N-1]-A[x+d2+i][y+d2-i];
					e=sum-(a+b+c+d);
					int m=min(a, min(b, min(c, min(d, e))));
					int M=max(a, max(b, max(c, max(d, e))));
					M-=m;
					if(ans>M)	ans=M;
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
