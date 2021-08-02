#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N;
bool chk[1000];
struct point{
	int x, y;
	bool operator<(const point &p)const{
		return x!=p.x ? x<p.x:y<p.y;
	}
}P[1000], J, T[1000];
int ch[1000];
int ccw(point a, point b, point c){
	int x1=b.x-a.x, x2=c.x-a.x;
	int y1=b.y-a.y, y2=c.y-a.y;
	ll ret=1ll*x1*y2-1ll*x2*y1;
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	else return -1;
}
bool sol(){
	int i, top=1, cnt=0;
	if(N<=2)	return false;
	ch[0]=0;
	ch[1]=1;
	for(i=2;i<N;++i){
		while(top>0 && ccw(P[ch[top-1]], P[ch[top]], P[i])<=0)	top--;
		ch[++top]=i;
	}
	for(i=0;i<top;++i){
		chk[ch[i]]=true;
		T[cnt++]=P[ch[i]];
	}
	top=1;
	ch[0]=0;
	ch[1]=1;
	for(i=2;i<N;++i){
		while(top>0 && ccw(P[ch[top-1]], P[ch[top]], P[i])>=0)	top--;
		ch[++top]=i;
	}
	for(i=top;i>0;--i){
		chk[ch[i]]=true;
		T[cnt++]=P[ch[i]];
	}
	T[cnt]=P[0];
	int c1=0, c2=0;
	for(i=0;i<cnt;++i){
		if(ccw(T[i], T[i+1], J)>=0)	c1=1;
		if(ccw(T[i], T[i+1], J)<=0)	c2=1;
	}
	if(c1 && c2)	return false;
	cnt=0;
	for(i=0;i<N;++i){
		if(!chk[i])	P[cnt++]=P[i];
		chk[i]=false;
	}
	N=cnt;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>J.x>>J.y;
	for(int i=0;i<N;++i){
		cin>>P[i].x>>P[i].y;
	}
	sort(P, P+N);
	int ans=0;
	while(sol()){
		ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
