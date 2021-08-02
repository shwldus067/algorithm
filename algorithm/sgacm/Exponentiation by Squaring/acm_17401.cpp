#include<iostream>
#include<vector>
using namespace std;
const int mod=1000000007;
typedef vector<vector<long long> > matrix;
matrix operator*(const matrix &a, const matrix &b){
	int n=a.size();
	matrix c(n, vector<long long>(n, 0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				c[i][j]+=a[i][k]*b[k][j];
				c[i][j]%=mod;
			}
		}
	}
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T, N, D, M, a, b, c, rem, exp;
	cin>>T>>N>>D;
	vector<matrix> route(T, matrix(N, vector<long long>(N, 0)));
	for(int t=0;t<T;t++){
		cin>>M;
		while(M--){
			cin>>a>>b>>c;
			route[t][a-1][b-1]=c;
		}
	}
	matrix ans(N, vector<long long>(N, 0));
	matrix base(N, vector<long long>(N, 0));
	matrix res(N, vector<long long>(N, 0));
	for(int i=0;i<N;i++){
		ans[i][i]=1;
		base[i][i]=1;
	}
	rem=D%T;
	for(int t=0;t<T;t++){
		if(t==rem){
			res=base;
		}
		base=base*route[t];
	}
	exp=D/T;
	while(exp){
		if(exp&1){
			ans=ans*base;
		}
		base=base*base;
		exp>>=1;
	}
	ans=ans*res;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<ans[i][j]<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
