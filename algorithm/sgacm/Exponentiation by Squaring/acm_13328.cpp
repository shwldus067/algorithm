#include<iostream>
#include<vector>
using namespace std;
const int mod=31991;
typedef vector<vector<int> > matrix;
matrix operator*(const matrix &a, const matrix &b){
	int n=a.size();
	matrix c(n, vector<int>(n, 0));
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
	int d, t, dt, tcall;
	cin>>d>>t;
	matrix res(d, vector<int>(d, 0));
	matrix ans(d, vector<int>(d, 0));
	int calls[d+1];
	for(int i=0;i<d;i++)	ans[0][i]=1;
	for(int i=1;i<d;i++){
		ans[i][i-1]=1;
		res[i][i]=1;
	}
	res[0][0]=1;
	calls[0]=calls[1]=1;
	for(int i=2;i<=d;i++){
		calls[i]=calls[i-1]*2;
		calls[i]%=mod;
	}
	dt=t-d;
	if(dt<=0){
		cout<<calls[t]<<"\n";
		return 0;
	}
	while(dt){
		if(dt&1){
			res=res*ans;
		}
		ans=ans*ans;
		dt>>=1;
	}
	tcall=0;
	for(int i=0;i<d;i++){
		tcall+=res[0][i]*calls[d-i];
		tcall%=mod;
	}
	cout<<tcall<<"\n";
	return 0;
}
