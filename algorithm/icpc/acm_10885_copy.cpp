#include<iostream>
using namespace std;
typedef long long ll;
const ll mod=1000000007;
int a[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		int N;
		cin>>N;
		ll ans=-3;
		int res=0;
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
		while(res--)	ans=ans*2%mod;
		cout<<ans<<"\n";
	}
	return 0;
}
