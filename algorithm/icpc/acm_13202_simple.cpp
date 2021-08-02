#include<cstdio>
#include<cmath>
using namespace std;
#define PI 3.14159265358979323846
int main(){
	int T;
	scanf("%d", &T);
	while(T--){
		double a, b, ans, r, r1, r2, r3, c1, c2, c3;
		int k;
		scanf("%lf %lf %d", &a, &b, &k);
		r=((a+b)-sqrt(a*a+b*b))/2;
		ans=PI*r*r;
		r1=3-2*sqrt(2);r1*=r1;
		r2=sqrt(2*r*r-2*a*r+a*a);r2=(r2-r)/(r2+r);r2*=r2;
		r3=sqrt(2*r*r-2*b*r+b*b);r3=(r3-r)/(r3+r);r3*=r3;
		c1=ans*r1;c2=ans*r2;c3=ans*r3;
		while(--k){
			if(c1>=c2 && c1>=c3)	ans=c1, c1*=r1;
			else if(c2>=c1 && c2>=c3)	ans=c2, c2*=r2;
			else	ans=c3, c3*=r3;
		}
		printf("%.10lf\n", ans);
	}
	return 0;
}
