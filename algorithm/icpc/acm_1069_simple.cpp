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
//	1. �׳� �ȴ´�
//	2. �� �������� n�� �����ϰ� �������� �ȴ´�
//	3.1. n>0; �밢������ n+1�� �����Ѵ� 
//	3.2. n=0; �밢������ 2�� ���� or �� �������� 1�� �����ϰ� �������� �ȴ´�
	return 0;
}
