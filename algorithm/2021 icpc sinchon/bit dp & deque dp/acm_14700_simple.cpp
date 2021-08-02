#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int N, M, nemo[2][1<<18];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	if(N<M)	swap(N, M);
	int K=2<<M, kk=K>>1, k=3+kk, ans=0, t=0, p=1;
	nemo[1][0]=1;
	for(int i=0;i<N*M;++i){
		for(int j=0;j<K;++j){
			nemo[t][j]=nemo[p][j>>1];
			if(!(i%M) || (j&k)!=k)
				nemo[t][j]=(nemo[t][j]+nemo[p][(j>>1)+kk])%mod;
		}
		t^=1, p^=1;
	}
	for(int i=0;i<K;++i)	ans=(ans+nemo[p][i])%mod;
	cout<<ans<<"\n";
	return 0;
}
