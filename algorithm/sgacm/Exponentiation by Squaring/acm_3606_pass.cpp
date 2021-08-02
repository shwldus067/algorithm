#include<iostream>
#include<vector>
using namespace std;
typedef vector<long long> vll;
int mod;
vll operator*(const vll& a, const vll& b){
	int n=a.size();
	vll c(n, 0);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i]+=a[j]*b[(n-i+j)%n];
			c[i]%=mod;
		}
	}
	return c;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, d, k;
	cin>>n>>m>>d>>k;
	mod=m;
	int A[n];
	for(int i=0;i<n;i++)	cin>>A[i];
	vll tmp(n, 0);
	vll res(n, 0);
	long long ans;
	res[0]=1;
	tmp[0]=1;
	for(int i=1;i<=d;i++)	tmp[i]=tmp[n-i]=1;
	while(k){
		if(k&1){
			res=res*tmp;
		}
		tmp=tmp*tmp;
		k>>=1;
	}
	for(int i=0;i<n;i++){
		ans=0;
		for(int j=0;j<n;j++){
			ans+=A[j]*res[(n-i+j)%n];
			ans%=m;
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
	return 0;
}
