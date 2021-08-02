#include<iostream>
using namespace std;
int chk[1000001];
long long arr[3001];
long long d[3001][3001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, t, m, k;
	long long ans=0;
	cin>>N;
	for(int i=1;i<=N;++i){
		cin>>arr[i];chk[arr[i]]=i;
	}
	for(int i=N-1;i>0;--i){
		for(int j=N;j>i;--j){
			int t=arr[j]-arr[i]+arr[j];
			if(t>1e6)	continue;
			t=chk[t];
			if(t)	d[i][j]=max(3*arr[j], arr[i]+d[j][t]);
			ans=max(ans, d[i][j]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
