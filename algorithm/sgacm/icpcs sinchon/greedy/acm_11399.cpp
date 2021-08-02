#include<iostream>
#include<algorithm>
using namespace std;
int N, arr[1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	sort(arr, arr+N);
	int ans=0;
	for(int i=0;i<N;++i)
		ans+=arr[i]*(N-i);
	cout<<ans<<"\n";
	return 0;
}
