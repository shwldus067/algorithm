#include<iostream>
using namespace std;
int N, fw[(1<<18)+1], base=1;
int sum(int idx){
	int ret=0;
	while(idx){
		ret+=fw[idx];
		idx-=idx&-idx;
	}
	return ret;
}
void update(int idx, int d){
	if(d==-1)	d=sum(idx-1)-sum(idx);
	while(idx<=base){
		fw[idx]+=d;
		idx+=idx&-idx;
	}
}
int find(int d){
	int idx=0;
	for(int i=base>>1;i;i>>=1){
		if(fw[i+idx]<d){
			idx+=i;
			d-=fw[idx];
		}
	}
	return idx+1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	while(base<N)	base*=2;
	for(int i=0;i<N;++i){
		int t;
		cin>>t;
		update(i+1, t);
	}
	for(int i=0;i<N;++i){
		int p;
		cin>>p;
		p=find(p);
		cout<<p<<" ";
		update(p, -1);
	}
	return 0;
}
