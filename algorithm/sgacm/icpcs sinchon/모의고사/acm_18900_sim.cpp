#include<iostream>
using namespace std;
int N, arr[1000001], ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int t;
		cin>>t;
		arr[t]=i;
	}
	ans=1;
	for(int i=N-2;i>0;--i){
		if(1ll*(arr[i+1]-arr[i])*(arr[i+2]-arr[i+1])<0){
			ans++;
			i--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
