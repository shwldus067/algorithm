#include<iostream>
using namespace std;
const int mod=1000000007;
long long N;
int M, a[100], c[100], r[100], t[200];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;++i)	a[i]=1;
	c[0]=c[M-1]=1;
	long long num=1;
	while(N>=M){
		num=num*2+N%2;
		N/=2;
	}
	r[N]=1;
	for(;num>1;num/=2){
		int tmp=num%2;
		for(int i=0;i<M*2;++i)	t[i]=0;
		for(int i=0;i<M;++i){
			for(int j=0;j<M;++j){
				t[i+j+tmp]=(t[i+j+tmp]+1ll*r[i]*r[j]%mod)%mod;
			}
		}
		for(int i=M-1;i>=0;--i){
			int v=t[i+M];
			for(int j=0;j<M;++j){
				t[i+j]=(t[i+j]+1ll*c[j]*v%mod)%mod;
			}
		}
		for(int i=0;i<M;++i)	r[i]=t[i];
	}
	int z=0;
	for(int i=0;i<M;++i){
		z=(z+1ll*a[i]*r[i]%mod)%mod;
	}
	cout<<z<<"\n";
	return 0;
}
