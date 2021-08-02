#include<iostream>
using namespace std;
const int mod=1000000003;
int d[1001][1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, m;
	cin>>N>>K;
	for(int i=1;i<=N;++i){
		d[i][0]=1;
		d[i][1]=i;
	}
	for(int i=2;i<=N;++i){
		for(int j=2;j<=N;++j){
			d[i][j]=(d[i-1][j]+d[i-2][j-1])%mod;
		}
	}
	cout<<(d[N-3][K-1]+d[N-1][K])%mod<<"\n";
	return 0;
}
