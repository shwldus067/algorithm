#include<iostream>
#include<algorithm>
using namespace std;
const long long mod=1000000007;
int N, pre, cur;
int arr[300000];
long long res;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	sort(arr, arr+N);
	long long tmp=0, p=2;
	for(int i=1;i<N;++i){
		tmp=(tmp*2+(arr[i]-arr[i-1])*1ll*(p-1))%mod;
		res=(res+tmp)%mod;
		p=(p*2)%mod;
	}
	cout<<res<<"\n";
	return 0;
}
