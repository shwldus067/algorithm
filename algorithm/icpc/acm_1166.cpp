#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	int N, L, W, H;
	scanf("%d %d %d %d", &N, &L, &W, &H);
	double l=0, r=1e9;
	for(int i=0;i<100;++i){
		double m=(l+r)/2;
		double a=floor(L/m), b=floor(W/m), c=floor(H/m);
		if(a*b*c>=N)	l=m;
		else	r=m;
	}
	printf("%.10lf", l);
	return 0;
}
