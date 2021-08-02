#include<iostream>
using namespace std;
#define ll long long
int N, arr[1000000];
ll sol(int l, int r){
	if(l==r)	return 1ll*arr[l]*arr[l];
	int mid=(l+r)/2;
	ll res1=sol(l, mid);
	ll res2=sol(mid+1, r);
	ll m=arr[mid]<arr[mid+1] ? arr[mid]:arr[mid+1];
	ll sum=arr[mid]+arr[mid+1];
	ll res3=m*sum;
	int idx1=mid-1, idx2=mid+2;
	while(l<=idx1 && idx2<=r){
		if(arr[idx1]<arr[idx2]){
			m=m<arr[idx2] ? m:arr[idx2];
			sum+=arr[idx2++];
		}
		else{
			m=m<arr[idx1] ? m:arr[idx1];
			sum+=arr[idx1--];
		}
		res3=res3>sum*m ? res3:sum*m;
	}
	while(l<=idx1){
		m=m<arr[idx1] ? m:arr[idx1];
		sum+=arr[idx1--];
		res3=res3>sum*m ? res3:sum*m;
	}
	while(r>=idx2){
		m=m<arr[idx2] ? m:arr[idx2];
		sum+=arr[idx2++];
		res3=res3>sum*m ? res3:sum*m;
	}
	ll M=res2>res3 ? res2:res3;
	return res1>M ? res1:M;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>arr[i];
	cout<<sol(0, N-1)<<"\n";
	return 0;
}
