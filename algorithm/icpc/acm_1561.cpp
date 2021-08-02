#include<iostream>
using namespace std;
typedef long long ll;
ll N;
int M, arr[10000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;++i)	cin>>arr[i];
	if(N<=M){
		cout<<N<<"\n";
		return 0;
	}
	ll l=0, r=6e10, time, sum;
	while(l<=r){
		ll m=(l+r)/2, cnt=(ll)M;
		for(int i=0;i<M;++i)	cnt+=m/(ll)arr[i];
		if(cnt>=N)	r=m-1, time=m;
		else	l=m+1, sum=cnt;
	}
	for(int i=0;i<M;++i){
		if(time%arr[i]==0)	sum++;
		if(sum==N){
			cout<<i+1<<"\n";
			return 0;
		}
	}
	return 0;
}
