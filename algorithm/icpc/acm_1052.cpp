#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K, ans=0, cnt=0;
	cin>>N>>K;
	for(int i=1;i<=N;i*=2)if(N&i)	++cnt;
	for(int i=1;i<=N;i*=2){
		if(cnt<=K){
			cout<<ans<<"\n";
			return 0;
		}
		if(N&i){
			ans+=i;
			N+=i;
			cnt=0;
			for(int j=i;j<=N;j*=2){
				if(N&j)	++cnt;
			}
		}
	}
	cout<<"-1\n";
	return 0;
}
