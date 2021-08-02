#include<cstdio>
#include<algorithm>
using namespace std;
int N;
struct point{
	int x, y;
};
struct line{
	point p1, p2;
}L[3000];
int p[3000], sz[3000];
int ccw(point &a, point &b, point &c){
	int ret=(b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
	if(ret>0)	return 1;
	else if(ret<0)	return -1;
	else	return 0;
}
bool cross(line &l1, line &l2){
	int c0=ccw(l1.p1, l1.p2, l2.p1);
	int c1=ccw(l1.p1, l1.p2, l2.p2);
	bool res=(c0*c1<=0) && (ccw(l2.p1, l2.p2, l1.p1)*ccw(l2.p1, l2.p2, l1.p2)<=0);
	if(!c0 && !c1){
		int x1=l1.p1.x, x2=l1.p2.x, x3=l2.p1.x, x4=l2.p2.x;
		int y1=l1.p1.y, y2=l1.p2.y, y3=l2.p1.y, y4=l2.p2.y;
		if(x1>x2)	swap(x1, x2);
		if(x3>x4)	swap(x3, x4);
		if(y1>y2)	swap(y1, y2);
		if(y3>y4)	swap(y3, y4);
		if(x2<x3 || x4<x1 || y2<y3 || y4<y1)	res=false;
	}
	return res;
}
int parent(int a){
	int &ret=p[a];
	while(p[ret]!=ret)	ret=p[ret];
	return ret;
}
void merge(int u, int v){
	int up=parent(u);
	int vp=parent(v);
	if(up==vp)	return;
	if(vp<up)	swap(up, vp);
	p[vp]=up;
	sz[up]+=sz[vp];
}
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;++i){
		scanf("%d %d %d %d", &L[i].p1.x, &L[i].p1.y, &L[i].p2.x, &L[i].p2.y);
		p[i]=i;
		sz[i]=1;
	}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(cross(L[i], L[j]))	merge(i, j);
		}
	}
	int cnt=0, maxsz=0;
	for(int i=0;i<N;++i){
		if(p[i]==i){
			++cnt;
			maxsz=max(maxsz, sz[i]);
		}
	}
	printf("%d\n%d\n", cnt, maxsz);
	return 0;
}
