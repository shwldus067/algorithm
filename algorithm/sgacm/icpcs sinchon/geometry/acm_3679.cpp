#include<iostream>
#include<algorithm>
using namespace std;
int c, n;
struct point{
	int x, y, n;
}P[2000];
int ccw(point &a, point &b, point &c){
	int ret=(b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
	if(ret>0)	return 1;
	if(ret==0)	return 0;
	else	return -1;
}
bool cmp(point &a, point &b){
	int ret=ccw(P[0], a, b);
	if(ret==0){
		int dx=a.x-P[0].x, dy=a.y-P[0].y;
		int da=dx*dx+dy*dy;
		dx=b.x-P[0].x, dy=b.y-P[0].y;
		return da>dx*dx+dy*dy;
	}
	else return ret==1;
}
bool mincmp(point &a, point &b){
	return a.x==b.x ? a.y<b.y:a.x<b.x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	while(c--){
		cin>>n;
		for(int i=0;i<n;++i){
			int x, y;
			cin>>x>>y;
			P[i]={x, y, i};
		}
		swap(P[0], *min_element(P, P+n, mincmp));
		sort(P+1, P+n, cmp);
		int k=1;
		for(;ccw(P[0], P[k], P[k+1])==0;++k);
		cout<<P[0].n;
		for(int i=k;i>0;--i){
			cout<<" "<<P[i].n;
		}
		for(int i=k+1;i<n;++i){
			cout<<" "<<P[i].n;
		}
		cout<<"\n";
	}
	return 0;
}
