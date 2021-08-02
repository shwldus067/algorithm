#include<stdio.h>
typedef long long ll;
int ccw(ll a, ll b, ll c, ll d, ll e, ll f){
	ll ret=(c-a)*(f-b)-(d-b)*(e-a);
	if(ret>0)	return 1;
	if(ret<0)	return -1;
	return 0;
}
int main(){
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	printf("%d", ccw(x1, y1, x2, y2, x3, y3)*ccw(x1, y1, x2, y2, x4, y4)<0 && ccw(x3, y3, x4, y4, x1, y1)*ccw(x3, y3, x4, y4, x2, y2)<0);
}
