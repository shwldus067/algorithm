#include<iostream>
using namespace std;
const int mod=1000000;
long long n, ans[2][2]={1, 0, 0, 1}, m[2][2]={1, 1, 1, 0}, t[2][2];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==0){
		cout<<"0\n";
		return 0;
	}
	if(n==1){
		cout<<"1\n";
		return 0;
	}
	n--;
	while(n){
		if(n&1){
			for(int i=0;i<2;++i){
				for(int j=0;j<2;++j){
					t[i][j]=0;
					for(int k=0;k<2;++k){
						t[i][j]=(t[i][j]+ans[i][k]*m[k][j]%mod)%mod;
					}
				}
			}
			ans[0][0]=t[0][0], ans[0][1]=t[0][1];
			ans[1][0]=t[0][1], ans[1][1]=t[1][1];
		}
		for(int i=0;i<2;++i){
			for(int j=0;j<2;++j){
				t[i][j]=0;
				for(int k=0;k<2;++k){
						t[i][j]=(t[i][j]+m[i][k]*m[k][j]%mod)%mod;
				}
			}
		}
		m[0][0]=t[0][0], m[0][1]=t[0][1];
		m[1][0]=t[0][1], m[1][1]=t[1][1];
		n>>=1;
	}
	cout<<ans[0][0]<<"\n";
	return 0;
}
