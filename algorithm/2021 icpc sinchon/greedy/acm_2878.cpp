#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, arr[100000];
	unsigned long long ans=0, sum;
	cin>>M>>N;
	sum=-M;
	for(int i=0;i<N;++i){
		cin>>arr[i];
		sum+=arr[i];
	}
	sort(arr, arr+N);
	for(int i=0;i<N;++i){
		unsigned long long r=min((unsigned long long)arr[i], sum/(N-i));
		ans+=r*r;
		sum-=r;
	}
	cout<<ans<<"\n";
	return 0;
}
