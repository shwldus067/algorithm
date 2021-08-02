#include<iostream>
#include<algorithm>
using namespace std;
int L, K, C, arr[10002], res, l, r, mid;
bool func(int x){
	int prev=0, cnt=0;
	if(arr[x-1]>mid)	return false;
	for(int i=x;i<=K+1;i++){
		if(arr[i]-arr[i-1]>mid)	return false;
		if(prev+arr[i]-arr[i-1]>mid){
			cnt++;
			prev=arr[i]-arr[i-1];
			if(cnt>C)	return false;
		}
		else{
			prev+=arr[i]-arr[i-1];
		}
	}
	res=mid;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>L>>K>>C;
	for(int i=1;i<=K;i++){
		cin>>arr[i];
	}
	sort(arr+1, arr+K+1);
	arr[K+1]=L;
	l=0, r=L;
	while(l<=r){
		mid=(l+r)/2;
		if(func(1))	r=mid-1;
		else	l=mid+1;
	}
	mid=res;
	C--;
	int k;
	for(k=1;k<=K;k++){
		if(func(k+1))	break;
	}
	cout<<res<<" "<<arr[k]<<"\n";
	return 0;
}
