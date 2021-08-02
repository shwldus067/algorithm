#include<iostream>
using namespace std;
struct point{
	int y, x;
	bool operator<(const point &a){
		if(y!=a.y)	return y<a.y;
		else	return x<a.x;
	}
	bool operator==(const point &a){
		return y==a.y && x==a.x;
	}
}s, e;
struct line{
	point p1, p2;
	int n;
	void f(void){
		if(p2<p1)	swap(p1, p2);
	}
}bus[5002];
int N, M, K;
bool cross(line l1, line l2){
	if(l1.p1.y>l2.p2.y || l1.p2.y<l2.p1.y)	return 0;
	if(l1.p1.x>l2.p2.x || l1.p2.x<l2.p1.x)	return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>M>>N>>K;
	int t, front=0, rear=1;
	for(int i=1;i<=K;++i){
		cin>>t>>bus[i].p1.x>>bus[i].p1.y>>bus[i].p2.x>>bus[i].p2.y;
		bus[i].f();
	}
	cin>>s.x>>s.y>>e.x>>e.y;
	bus[0]={s, s};bus[++K]={e, e};
	while(front<rear){
		line tmp=bus[front];
		if(bus[front].p1==e && bus[front].p2==e)	break;
		for(int j=rear;j<=K;++j){
			if(cross(bus[front], bus[j])){
				bus[j].n=bus[front].n+1;
				swap(bus[rear++], bus[j]);
			}
		}
		front++;
	}
	cout<<bus[front].n-1<<"\n";
	return 0;
}
