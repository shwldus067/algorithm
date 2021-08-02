#include<iostream>
using namespace std;
int Lx, Ly, N;
int lx[20000], ly[20000], lz[20000], px[20000], py[20000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>Lx>>Ly>>N;
	for(int i=0;i<N;++i){
		cin>>lx[i]>>ly[i]>>lz[i]>>px[i]>>py[i];
	}
	int ans=lz[0];
	for(int i=1;i<N;++i){
		int l, r, u, d;
		l=px[i], r=px[i]+lx[i];
		d=py[i], u=py[i]+ly[i];
		int tmp=0;
		for(int j=0;j<i;++j){
			if(px[j]+lx[j]<=l || px[j]>=r || py[j]+ly[j]<=d || py[j]>=u)
				continue;
			tmp=max(tmp, lz[j]);
		}
		lz[i]+=tmp;
		ans=max(ans, lz[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
