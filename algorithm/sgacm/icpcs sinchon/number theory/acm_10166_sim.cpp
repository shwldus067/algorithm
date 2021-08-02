#include<iostream>
using namespace std;
int d1, d2, arr[2001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>d1>>d2;
	int ans=1;
	for(int i=1;i<=d2;++i){
		arr[i]=i-1;
	}
	for(int i=2;i*2<=d2;++i){
		for(int j=i*2;j<=d2;j+=i){
			arr[j]-=arr[i];
		}
	}
	for(int i=d1-1;i>0;--i){
		if(d2/i==(d1-1)/i){
			arr[i]=0;
		}
	}
	for(int i=1;i<=d2;++i)	ans+=arr[i];
	cout<<ans<<"\n";
	return 0;
}
