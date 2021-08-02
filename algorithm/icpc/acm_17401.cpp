#include<iostream>
#include<vector>
#include<array>
using namespace std;
typedef array<array<long long, 20>, 20> matrix;
const int mod=1000000007;
int T, N, D, M;
matrix mul(const matrix&a, const matrix &b){
	matrix res={};
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			for(int k=0;k<N;++k)
				res[i][j]=(res[i][j]+a[i][k]*b[k][j])%mod;
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T>>N>>D;
	vector<matrix> route(T, matrix{});
	int a, b, c;
	for(int i=0;i<T;++i){
		cin>>M;
		while(M--){
			cin>>a>>b>>c;
			route[i][a-1][b-1]=c;
		}
	}
	matrix ans{}, base{}, rem{};
	for(int i=0;i<N;++i){
		ans[i][i]=base[i][i]=1;
	}
	a=D%T, b=D/T;
	for(int i=0;i<T;++i){
		if(i==a)	rem=base;
		base=mul(base, route[i]);
	}
	while(b){
		if(b&1)	ans=mul(ans, base);
		base=mul(base, base);
		b>>=1;
	}
	ans=mul(ans, rem);
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j)	cout<<ans[i][j]<<" ";
		cout<<"\n";
	}
	return 0;
}
