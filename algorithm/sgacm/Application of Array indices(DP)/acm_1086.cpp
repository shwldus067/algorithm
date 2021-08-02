#include<iostream>
#include<string>
using namespace std;
typedef long long ll;
int N, K;
int num[16], val[51], arr[16];
ll dp[1<<16][101];
string inp[16];
ll gcd(ll a, ll b){
	if(b==0)	return a;
	return gcd(b, a%b);
}
ll f(int bit, int mod){
	if(bit==(1<<N)-1){
		if(mod==0)	return 1;
		else	return 0;
	}
	ll &ret=dp[bit][mod];
	if(ret!=-1)	return ret;
	ret=0;
	for(int i=0;i<N;i++){
		if(!(bit&(1<<i))){
			ret+=f(bit|(1<<i), (val[num[i]]*mod+arr[i])%K);
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>inp[i];
	}
	cin>>K;
	for(int i=0;i<N;i++){
		for(int k=0;k<inp[i].size();k++){
			arr[i]=(arr[i]*10+inp[i][k]-'0')%K;
		}
		num[i]=inp[i].size();
	}
	val[0]=1;
	for(int i=1;i<=50;i++)	val[i]=val[i-1]*10%K;
	fill(&dp[0][0], &dp[(1<<15)-1][100], -1);
	ll a, b, c;
	a=1;
	for(ll i=2;i<=N;i++)	a*=i;
	b=f(0, 0);
	c=gcd(a, b);
	cout<<b/c<<"/"<<a/c<<"\n";
	return 0;
}
