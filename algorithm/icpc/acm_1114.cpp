#include<iostream>
#include<algorithm>
using namespace std;
int L, K, C, arr[10002], res, l, r, mid;
bool func(int x){
	int prev=0, cnt=0;
	for(int i=K;i>=0;i--){
		prev+=arr[i+1]-arr[i];
		if(prev>x){
			prev=arr[i+1]-arr[i];
			cnt++;
			if(prev>x)	return false;
		}
	}
	return cnt<=C;
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
	res=L;
	//최대 C번 잘라서 만들 수 있는 가장 긴 토막의 길이
	//binary_search
	while(l<=r){
		mid=(l+r)/2;
		if(func(mid)){	//가장 긴 토막의 길이로 mid 가능
			res=min(res, mid);
			r=mid-1;
		}
		else	l=mid+1;
	}
	int prev=0, cnt=0, k=K+1;
	for(int i=K;i>=0;i--){
		prev+=arr[i+1]-arr[i];
		if(prev>res){
			cnt++;
			prev=arr[i+1]-arr[i];
			k=i+1;
		}
	}
	if(cnt<C)	k=1;
	cout<<res<<" "<<arr[k]<<"\n";
	return 0;
}
