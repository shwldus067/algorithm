#include<iostream>
using namespace std;
typedef long long ll;
int N, pow[20], W[262144], arr[262144];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int D=0;
	ll ans=-1e9;
	cin>>N;
	for(int i=1;i<=N;++i)	cin>>W[i];
	pow[0]=1;
	for(int i=1;i<20;++i){
		pow[i]=pow[i-1]*2;
		if(pow[i]==N+1){
			D=i;
			break;
		}
	}
	int t=2, idx=1;
	for(int i=D-1;i>=0;--i){
		for(int j=pow[i], k=idx;j<pow[i+1];j++, k+=t){
			arr[k]=j;
		}
		t+=t;
		idx+=idx;
	}
	for(int i=0;i<D;++i){
		for(int j=i+1;j<=D;++j){
			ll res, sum;
			res=sum=W[arr[pow[D-j]]];
			for(int k=pow[D-j]+1;k<=N;++k){
				if(arr[k]<pow[i] || arr[k]>=pow[j])	continue;
				sum=max(sum+W[arr[k]], (ll)W[arr[k]]);
				if(sum>res)	res=sum;
			}
			if(res>ans)	ans=res;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
