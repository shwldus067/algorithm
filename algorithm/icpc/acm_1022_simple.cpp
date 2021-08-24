#include<cstdio>
int max(int a, int b){return a>b?a:b;}
int abs(int k){return k<0?-k:k;}
int sol(int r, int c){
	int t=max(abs(r), abs(c));
	int res=2*t+1;
	res*=res;
	if(r==-t)	res-=5*t+c;
	else if(r==t)	res-=t-c;
	else if(c==-t)	res-=3*t-r;
	else	res-=7*t+r;
	return res;
}
int main(){
	int r1, c1, r2, c2, arr[50][5], M=0;
	scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
	int rr=r2-r1+1, cc=c2-c1+1;
	for(int i=r1;i<=r2;++i){
		for(int j=c1;j<=c2;++j){
			arr[i-r1][j-c1]=sol(i, j);
			M=max(M, arr[i-r1][j-c1]);
		}
	}
	int ml=0;
	for(int l=1;l<=M;l*=10)	++ml;
	for(int i=0;i<rr;++i){
		for(int j=0;j<cc;++j){
			printf("%*d ", ml, arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
