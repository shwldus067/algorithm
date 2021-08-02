#include<iostream>
using namespace std;
int N, seg[1<<19], w[200000];
int init(int s, int e, int x){
	if(s==e)	return seg[x]=w[s];
	int m=(s+e)/2, nx=x<<1;
	return seg[x]=init(s, m, nx)+init(m+1, e, nx+1);
}
void update(int s, int e, int x, int d){
	seg[x]-=w[d];
	if(s==e)	return;
	int m=(s+e)/2, nx=x<<1;
	if(m<d)	update(m+1, e, nx+1, d);
	else	update(s, m, nx, d);
}
int find(int s, int e, int x, int d){
	if(s==e)	return s;
	int m=(s+e)/2, nx=x<<1;
	if(seg[nx]>=d)	return find(s, m, nx, d);
	else if(seg[nx]<d)	return find(m+1, e, nx+1, d-seg[nx]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>w[i];
	init(0, N-1, 1);
	for(int i=0;i<N;++i){
		int p;
		cin>>p;
		p=find(0, N-1, 1, p);
		cout<<p+1<<" ";
		update(0, N-1, 1, p);
	}
	return 0;
}
