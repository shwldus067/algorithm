#include<cstdio>
#include<cmath>
using namespace std;
#define min(a, b) a<b?a:b
int T, N, M, X[20], Y[20], sumx, sumy;
double ans;
void sol(int idx, int n, int dx, int dy){
	if(n==0){
		int x=sumx-(dx+dx), y=sumy-(dy+dy);
		ans=min(ans, sqrt(1ll*x*x+1ll*y*y));
		return;
	}
	for(int i=idx;i<=N-n;++i)	sol(i+1, n-1, dx+X[i], dy+Y[i]);
	return;
}
int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		sumx=sumy=0;
		for(int i=0;i<N;++i)	scanf("%d %d", X+i, Y+i), sumx+=X[i], sumy+=Y[i];
		ans=3e6;
		sol(1, (N>>1)-1, X[0], Y[0]);
		printf("%.12lf\n", ans);
	}
	return 0;
}
