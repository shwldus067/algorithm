#include<iostream>
using namespace std;
int N, arr[50001], ans[50000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t;
	for(int i=0;i<N;++i)	cin>>t, arr[t]=i;
	for(int i=N;i>0;--i){
		t=arr[i-1]>arr[i]?i-1:i;
		ans[arr[t]]=i;
		if(t==i-1)	ans[arr[i]]=i-1, --i;
	}
	for(int i=0;i<N;++i)	cout<<ans[i]<<"\n";
	return 0;
}
