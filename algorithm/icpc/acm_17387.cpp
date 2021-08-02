#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> pll;
pll p1, p2, p3, p4;
int ccw(pll &a, pll &b, pll &c){
	ll ret=(b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
	if(ret<0)	return -1;
	if(ret>0)	return 1;
	return 0;
}
bool chk(){
	int t1=ccw(p1, p2, p3)*ccw(p1, p2, p4);
	int t2=ccw(p3, p4, p1)*ccw(p3, p4, p2);
	if(t1==0 && t2==0){
		if(p1>p2) swap(p1, p2);
		if(p3>p4) swap(p3, p4);
		return p1<=p4 && p3<=p2;
	}
	return t1<=0 && t2<=0;
}
int main(){
	scanf("%lld %lld %lld %lld", &p1.first, &p1.second, &p2.first, &p2.second);
	scanf("%lld %lld %lld %lld", &p3.first, &p3.second, &p4.first, &p4.second);
	if(chk())	printf("1\n");
	else 	printf("0\n");
	return 0;
}
