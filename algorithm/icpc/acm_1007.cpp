#include<cstdio>
#include<cmath>
using namespace std;
#define min(a, b) a<b?a:b
int T, N, M, X[20], Y[20], dx, dy, sumx, sumy;
double ans;
bool chk[20];
void sol(int idx, int n){
	if(n==M){
		int x=sumx-(dx+dx), y=sumy-(dy+dy);
		ans=min(ans, sqrt(1ll*x*x+1ll*y*y));
		return;
	}
	if(N-idx==M-n){
		for(int i=idx;i<N;++i)	dx+=X[i], dy+=Y[i];
		sol(N-1, M);
		for(int i=idx;i<N;++i)	dx-=X[i], dy-=Y[i];
		return;
	}
	dx+=X[idx], dy+=Y[idx];
	sol(idx+1, n+1);
	dx-=X[idx], dy-=Y[idx];
	sol(idx+1, n);
	return;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		sumx=sumy=0;
		for(int i=0;i<N;++i)	scanf("%d %d", X+i, Y+i), sumx+=X[i], sumy+=Y[i];
		ans=3e6;
		dx=X[0], dy=Y[0];
		M=N>>1;
		sol(1, 1);
		printf("%.12lf\n", ans);
	}
	return 0;
}
