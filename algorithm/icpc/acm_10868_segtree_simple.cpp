#include<iostream>
using namespace std;
const int n=1<<17;
int seg[n<<1], N, M;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>seg[i+n];
	for(int i=N;i<n;++i)	seg[i+n]=1e9;
	for(int i=n-1;i>=1;--i)	seg[i]=min(seg[i*2], seg[i*2+1]);
	while(M--){
		int a, b;
		cin>>a>>b;
		a+=n-1, b+=n-1;
		int ans=1e9;
		while(a<=b){
			if(a&1)	ans=min(ans, seg[a++]);
			if(~b&1)	ans=min(ans, seg[b--]);
			a>>=1, b>>=1;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
