#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll absf(ll a){
	if(a<0)	return -a;
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, arr[5000], a, b, c, sum, ans=3e9;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	sort(arr, arr+N);
	for(int i=0;i<N-2;++i){
		for(int j=i+1;j<N-1;++j){
			sum=arr[i]+arr[j];
			ll tmp=lower_bound(arr+j+1, arr+N, -sum)-arr;
			if(tmp==N)	tmp--;
			if(absf(sum+arr[tmp])<ans)	ans=abs(sum+arr[tmp]), a=i, b=j, c=tmp;
			tmp--;
			if(tmp>j && absf(sum+arr[tmp])<ans)	ans=abs(sum+arr[tmp]), a=i, b=j, c=tmp;
		}
	}
	cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<"\n";
	return 0;
}
