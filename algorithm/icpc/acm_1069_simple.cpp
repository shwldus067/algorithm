#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int X, Y, D, T, n;
int main(){
	scanf("%d %d %d %d", &X, &Y, &D, &T);
	double dist=sqrt(X*X+Y*Y);
	n=dist/D;	//n*D<=dist<(n+1)*D
	printf("%.15lf\n", min({dist, dist-n*D+n*T, n ? (double)n*T+T:min(T*2.0, T+D-dist)}));
//	1. 그냥 걷는다
//	2. 집 방향으로 n번 점프하고 나머지는 걷는다
//	3.1. n>0; 대각선으로 n+1번 점프한다 
//	3.2. n=0; 대각선으로 2번 점프 or 집 방향으로 1번 점프하고 나머지는 걷는다
	return 0;
}
