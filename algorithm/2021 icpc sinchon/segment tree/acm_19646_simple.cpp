#include<iostream>
using namespace std;
int N, seg[1<<19], base=1;
void update(int idx){
	idx+=base-1;
	seg[idx]=0;idx>>=1;
	while(idx){
		seg[idx]=seg[idx*2]+seg[idx*2+1];
		idx>>=1;
	}
}
int find(int d){
	int idx=1;
	while(idx<base){
		idx*=2;
		if(seg[idx]<d)	d-=seg[idx], ++idx;
	}
	return idx-base+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(base<N)	base*=2;
	for(int i=0;i<N;++i)	cin>>seg[i+base];
	for(int i=base-1;i>0;--i)	seg[i]=seg[i*2]+seg[i*2+1];	//init
	for(int i=0;i<N;++i){
		int p;
		cin>>p;
		p=find(p);
		cout<<p<<" ";
		update(p);
	}
	return 0;
}
