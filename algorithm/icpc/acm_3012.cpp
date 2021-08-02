#include<iostream>
#include<string>
using namespace std;
const int mod=100000;
int N;
string s;
long long dp[200][200];
string o="({[";
string c=")}]";
long long fun(int l, int r){
	if(l>r)	return 1;
	long long &res=dp[l][r];
	if(res!=-1)	return res;
	res=0;
	for(int i=l+1;i<=r;i+=2){
		for(int j=0;j<3;j++){
			if(s[l]==o[j] || s[l]=='?'){
				if(s[i]==c[j] || s[i]=='?'){
					long long tp=fun(l+1, i-1)*fun(i+1, r);
					res+=tp;
					if(res>=mod){
						res=mod+res%mod;
					}
				}
			}
		}
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>s;
	if(N%2){
		cout<<0<<"\n";
		return 0;
	}
	fill(&dp[0][0], &dp[N-1][N], -1);
	long long ans=fun(0, N-1);
	if(ans>=mod){
		cout.width(5);
		cout.fill('0');
		cout<<ans%mod<<"\n";
	}
	else{
		cout<<ans<<"\n";
	}
	return 0;
}
