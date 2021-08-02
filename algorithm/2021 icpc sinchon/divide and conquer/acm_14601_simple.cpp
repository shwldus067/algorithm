#include<cstdio>
int K, idx, x, y, d[4][2]={{0, 0}, {0, 1}, {1, 0}, {1, 1}};
short arr[128][128];
int chk(int r, int c, int n){
	for(int i=0;i<n;++i)for(int j=0;j<n;++j)if(arr[r+i][c+j])	return 0;
	return 1;
}
void sol(int r, int c, int n){
	++idx;
	n>>=1;
	for(int i=0;i<4;++i){
		int dr=d[i][0], dc=d[i][1];
		if(chk(r+n*dr, c+n*dc, n))	arr[r+n-!dr][c+n-!dc]=idx;
	}
	if(n==1)	return;
	sol(r, c, n);sol(r+n, c, n);sol(r, c+n, n);sol(r+n, c+n, n);
}
int main(){
	scanf("%d %d %d", &K, &y, &x);
	K=1<<K;
	arr[K-x][--y]=-1;
	sol(0, 0, K);
	for(int i=0;i<K;++i, printf("\n")){
		for(int j=0;j<K;++j)	printf("%hi ", arr[i][j]);
	}
	return 0;
}
