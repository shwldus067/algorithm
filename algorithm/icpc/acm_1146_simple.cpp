#include<iostream>
using namespace std;
const int mod=1000000;
int N, d[101], s[101];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	if(N==1){
		cout<<"1\n";return 0;
	}else if(N==2){
		cout<<"2\n";return 0;
	}
	s[1]=s[2]=1;
	for(int i=3;i<=N;++i){
		for(int j=1;j<i-1;++j){
			d[i-j]=s[j];
		}
		for(int j=i-1;j;--j){
			s[j]=(s[j+1]+d[j])%mod;
		}
	}
	int ans=0;
	for(int i=1;i<N;++i){
		ans=(ans+2*d[i]*i)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
