#include<iostream>
using namespace std;
const int mod=9901;
int d[225][1<<14];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, K, L;
	cin>>N>>M;
	K=1<<M;L=N*M;
	d[L][0]=1;
	for(int i=L-1;i>=0;--i){
		for(int j=0;j<K;++j){
			if(j&1)	d[i][j]+=d[i+1][j>>1];
			if(!(j&1))	d[i][j]+=d[i+1][j>>1 | 1<<M-1];
			if(i%M!=M-1 && !(j&3))	d[i][j]+=d[i+1][j>>1 | 1];
			d[i][j]%=mod;
		}
	}
	cout<<d[0][0]<<"\n";
	return 0;
}
