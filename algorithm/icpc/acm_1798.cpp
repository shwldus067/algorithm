#define _USE_MATH_DEFINES
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
double PI=M_PI;
double getRadian(double a){
	return a*(PI/180);
}
int main(){
	double r, h, d1, A1, d2, A2, ans, d;
	while(scanf("%lf %lf %lf %lf %lf %lf", &r, &h, &d1, &A1, &d2, &A2)>0){
		d=sqrt(h*h+r*r);
		if(A1>A2)	swap(A1, A2);
		A2-=A1;
		if(A2>180)	A2=360-A2;
		printf("%.2lf\n", sqrt(d1*d1+d2*d2-2*d1*d2*cos(getRadian(A2)*r/d)));
	}
	return 0;
}
