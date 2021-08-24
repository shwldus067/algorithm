#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, arr[50001], ans[50001];
	cin>>n;
	int t, i;
	for(i=0;i<n;++i){
		cin>>t;
		arr[t]=i;
	}
	for(i=n;i>1;--i){
		if(arr[i]<arr[i-1]){
			ans[arr[i]]=i-1;
			ans[arr[i-1]]=i;
			i--;
		}
		else{
			ans[arr[i]]=i;
		}
	}
	if(i)	ans[arr[1]]=1;
	for(int i=0;i<n;++i)	cout<<ans[i]<<" ";
	return 0;
}
