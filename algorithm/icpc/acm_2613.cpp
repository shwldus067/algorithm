#include<iostream>
#include<algorithm>
using namespace std;
int N, M, arr[300];
bool sol(int x){
	int res=1, sum=0;
	for(int i=0;i<N;++i){
		if(arr[i]>x)	return false;
		sum+=arr[i];
		if(sum>x){
			res++, sum=arr[i];
		}
	}
	return res<=M;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>arr[i];
	int l=1, r=3e4, ans;
	while(l<=r){
		int m=(l+r)/2;
		if(sol(m))	r=m-1, ans=m;
		else	l=m+1;
	}
	int cnt=1, k=0, sum=0;
	cout<<ans<<"\n";
	for(int i=0;i<N && N-i+cnt>M;++i){
		sum+=arr[i];
		k++;
		if(sum>ans){
			cout<<k-1<<" ";
			cnt++;
			k=1, sum=arr[i];
		}
		if(i==N-1){
			cout<<k<<" ";
		}
	}
	if(cnt<M)	cout<<k<<" ";
	for(int i=cnt;i<M;++i){
		cout<<"1 ";
	}
	return 0;
}
