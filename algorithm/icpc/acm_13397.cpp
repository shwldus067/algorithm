#include<iostream>
using namespace std;
int N, M, arr[5000];
bool func(int n){
	int res=1, min=arr[0], max=arr[0];
	for(int i=1;i<N;++i){
		if(min>arr[i])	min=arr[i];
		if(max<arr[i])	max=arr[i];
		if(max-min>n)	min=max=arr[i], res++;
	}
	return res<=M;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int l=0, r=9999, ans=0;
	for(int i=0;i<N;++i){
		cin>>arr[i];
	}
	while(l<=r){
		int m=(l+r)/2;
		if(func(m))	r=m-1, ans=m;
		else	l=m+1;
	}
	cout<<ans<<"\n";
	return 0;
}
