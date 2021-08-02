#include<iostream>
#include<vector>
using namespace std;
typedef vector<vector<long long> > matrix;
int mod;
matrix operator*(const matrix& a, const matrix& b){
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
	int n, m, d, k;
	long long ans;
	cin>>n>>m>>d>>k;
	mod=m;
	int A[n];
	for(int i=0;i<n;i++)	cin>>A[i];
	matrix res(n, vector<long long>(n, 0));
	matrix tmp(n, vector<long long>(n, 0));
	for(int i=0;i<n;i++){
		tmp[i][i]=1;
		for(int j=1;j<=d;j++){
			tmp[i][(n+i-j)%n]=tmp[i][(i+j)%n]=1;
		}
	}
	for(int i=0;i<n;i++)	res[i][i]=1;
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
			ans+=res[i][j]*A[j];
			ans%=m;
		}
		cout<<ans<<" ";
	}
	cout<<"\n";
	return 0;
}
