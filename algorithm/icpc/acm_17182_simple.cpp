#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int N, K, M, T[10][10], d[1024][10];
int sol(int v, int x){
	if(v==M)	return 0;
	if(d[v][x]>=0)	return d[v][x];
	int ret=1e6;
	for(int i=0;i<N;++i)
		if(!(v&(1<<i)))	ret=min(ret, sol(v|(1<<i), i)+T[x][i]);
	return d[v][x]=ret;
}
int main(){
	scanf("%d %d", &N, &K);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	scanf("%d", &T[i][j]);
	for(int k=0;k<N;++k)for(int i=0;i<N;++i)for(int j=0;j<N;++j){
		T[i][j]=min(T[i][j], T[i][k]+T[k][j]);
	}
	M=(1<<N)-1;
	memset(d, -1, sizeof(d));
	printf("%d\n", sol(1<<K, K));
	return 0;
}
