#include<iostream>
using namespace std;
typedef long long ll;
const int MAX=1<<17;
int N, K, M, arr[250000], seg[MAX<<1];
int midval(){
	int i=1, val=M;
	while(i<MAX){
		if(seg[i*2]>=val)	i*=2;
		else{
			val=val-seg[i*2];
			i=i*2+1;
		}
	}
	return i-MAX;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	M=(K+1)/2;
	for(int i=0;i<N;++i)	cin>>arr[i];
	for(int i=0;i<K;++i)	seg[arr[i]+MAX]++;
	for(int i=MAX-1;i>=1;--i)	seg[i]=seg[i*2]+seg[i*2+1];
	ll ans=(ll)midval();
	for(int i=K;i<N;++i){
		for(int j=MAX+arr[i-K];j>=1;j>>=1)	seg[j]--;
		for(int j=MAX+arr[i];j>=1;j>>=1)	seg[j]++;
		ans+=(ll)midval();
	}
	cout<<ans<<"\n";
	return 0;
}
