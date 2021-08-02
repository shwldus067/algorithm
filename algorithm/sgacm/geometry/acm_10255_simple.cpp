#include<iostream>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
pii c, d;
int ccw(pii a, pii b, pii c){
	int ret=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	else	return -1;
}
int cross(pii a, pii b){
	int p=ccw(a, b, c), q=ccw(a, b, d);
	int r=ccw(c, d, a), s=ccw(c, d, b);
	if(p==0 && q==0 && r==0 && s==0){
		if(a>b)	swap(a, b);
		if(c>d)	swap(c, d);
		if(c==b || a==d)	return 1;
		return (a<d && c<b)<<3;
	}
	return p*q<=0 && r*s<=0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int sa, sb, sc, sd, sx, sy, ex, ey;
		cin>>sa>>sb>>sc>>sd>>sx>>sy>>ex>>ey;
		pii sq[]={{sa, sb}, {sa, sd}, {sc, sd}, {sc, sb}, {sa, sb}};
		c={sx, sy}, d={ex, ey};
		int res=0;
		for(int i=0;i<4;i++){
			res+=cross(sq[i], sq[i+1]);
			if(cross(sq[i], sq[i]))	res--;
		}
		if(res>=4)	cout<<"4\n";
		else	cout<<res<<"\n";
	}
	return 0;
}
