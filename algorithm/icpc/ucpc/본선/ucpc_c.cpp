#include<iostream>
#include<vector>
using namespace std;
const int mod=1000000007;
int N, a[501][501];
long long ans=1;
bool arr[501];
int fac[501];
int fact(int n){
	if(n==1)	return 1;
	if(fac[n])	return fac[n];
	long long ans=1ll*n*fact(n-1)%mod;
	return fac[n]=(int)ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>a[i][j];
		}
	}
	int f, t, s=0;
	for(int i=0;i<N;++i){
		s=0;
		for(int j=0;j<N;++j){
			if(i==j)	continue;
			f=1, t=1;
			for(int k=0;k<N;++k){
				if(a[i][k]!=a[j][k]){
					if(i==k){
						t=0;
						continue;
					}
					f=0;
					break;
				}
			}
			if(f && t){
				if(!arr[j]){
					arr[i]=true;
					arr[j]=true;
					s++;
				}
			}
		}
		if(s){
			ans*=1ll*fact(s);
			
			ans%=mod;
			s=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
