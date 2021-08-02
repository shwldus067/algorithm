#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
int N, pre, cur;
int arr[300000];
long long p[300000], res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	p[0]=1;
	cin>>arr[0];
	for(int i=1;i<N;++i){
		cin>>arr[i];
		p[i]=p[i-1]*2%mod;
	}
	sort(arr, arr+N);
	p[0]=1;
	for(int i=0;i<N;++i){
		res+=((long long)arr[i]*(p[i]-p[N-i-1]+mod))%mod;
		res%=mod;
	}
	cout<<res<<"\n";
	return 0;
}
