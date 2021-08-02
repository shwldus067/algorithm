#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
typedef vector<vector<int> > matrix;
const long long mod=1000000007;
int k, n, s;
matrix operator*(const matrix &a, const matrix &b){
	matrix c(s, vector<int>(s, 0));
	for(int i=0;i<s;++i){
		for(int j=0;j<s;++j){
			for(int k=0;k<s;++k){
				c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j]%mod)%mod;
			}
		}
	}
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>k>>n;
	if(k==0){
		cout<<n<<"\n";
		return 0;
	}
	s=k+2;
	matrix a(s, vector<int>(s, 0));
	for(int i=0;i<s;++i){
		for(int j=0;j<=i;++j){
			a[i][j]=1;
		}
	}
	matrix ans(s, vector<int>(s, 0));
	for(int i=0;i<s;++i){
		ans[i][i]=1;
	}
	--n;
	while(n){
		if(n&1)	ans=ans*a;
		a=a*a;
		n>>=1;
	}
	int res=0;
	for(int i=--s;i>=0;--i){
		res=(res+ans[s][i])%mod;
	}
	cout<<res<<"\n";
	return 0;
}
