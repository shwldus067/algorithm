#include<iostream>
using namespace std;
typedef long long ll;
int N, D, W[262144];
ll x[18][18], y[18][18];
void sol(int n, int d){
	if(d<D-1)	sol(n<<1, d+1);
	for(int i=0;i<=d;++i){
		for(int j=d;j<D;++j){
			y[i][j]=max(0ll, y[i][j])+W[n];
			x[i][j]=max(x[i][j], y[i][j]);
		}
	}
	if(d<D-1)	sol(n<<1|1, d+1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;++i)	cin>>W[i];
	for(;(1<<D)<=N;++D);
	for(int i=0;i<D;++i)for(int j=i;j<D;++j) x[i][j]=y[i][j]=-1e9;
	sol(1, 0);
	ll ans=-1e9;
	for(int i=0;i<D;++i){
		for(int j=i;j<D;++j){
			ans=max(ans, x[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
