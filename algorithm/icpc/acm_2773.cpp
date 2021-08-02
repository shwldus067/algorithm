#include<iostream>
using namespace std;
int main(){
	int T;
	double x1, x2, x3, y1, y2, y3, Ax, Ay, Bx, By, X, Y;
	scanf("%d", &T);
	while(T--){
		scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
		if(((x2-x1)*(y3-y1)-(y2-y1)*(x3-x1))<0)	swap(x2, x3), swap(y2, y3);
		Ax=(y3-y1)/2, Ay=(x1-x3)/2;
		Bx=(y1-y2)/2, By=(x2-x1)/2;
		if(Ax==0)	X=x2, Y=By/Bx*(X-x3)+y3;
		else{
			if(Bx==0)	X=x3;
			else	X=(Ay/Ax*x2-By/Bx*x3+y3-y2)/(Ay/Ax-By/Bx);
			Y=Ay/Ax*(X-x2)+y2;
		}
		printf("%.4lf %.4lf\n", X, Y);
	}
}
