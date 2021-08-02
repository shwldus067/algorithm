#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int a[100001];
ll pow(int b){
	ll ret=1, A=2;
	while(b){
		if(b&1)	ret=ret*A%mod;
		A=1ll*A*A%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		int ans=-3, res=0;
		for(int i=0;i<N;++i){
			cin>>a[i];
			if(ans<a[i])	ans=a[i];
		}
		int two=0, minus=0;
		for(int i=0;i<N;++i){
			if(a[i]==0){
				two=minus=0;
				continue;
			}
			else if(a[i]<0){
				++minus;
				if(a[i]==-2)	++two;
			}
			else if(a[i]==2)	++two;
			if(!(minus&1)){
				if(res<two)	res=two;
				ans=1;
			}
		}
		two=minus=0;
		for(int i=N-1;i>=0;--i){
			if(a[i]==0){
				two=minus=0;
				continue;
			}
			else if(a[i]<0){
				++minus;
				if(a[i]==-2)	++two;
			}
			else if(a[i]==2)	++two;
			if(!(minus&1)){
				if(res<two)	res=two;
				ans=1;
			}
		}
		if(res)	cout<<pow(res)<<"\n";
		else	cout<<ans<<"\n";
	}
	return 0;
}
