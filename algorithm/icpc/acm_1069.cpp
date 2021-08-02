#include<iostream>
#include<cmath>
using namespace std;
double X, Y, D, T, ans, d, t, p;
int main(){
	scanf("%lf %lf %lf %lf", &X, &Y, &D, &T);
	ans=sqrt(X*X+Y*Y);
	if(D>T){
		p=d=ans, t=0;
		while(1){
			d-=D;
			t+=T;
			if(t+abs(d)>ans)	break;
			ans=min(ans, t+abs(d));
		}
		d=p;
		for(double i=1;i<=d;++i){
			if(d>(i-1)*D && d<=(i+1)*D)	ans=min(ans, (i+1)*T);
		}
	}
	printf("%.15lf", ans);
}
