#include<iostream>
using namespace std;
int T, N;
int arr[1001], d[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		arr[0]=d[0]=0;
		for(int i=1;i<=N;++i){
			cin>>arr[i];
			d[i]=arr[i];
			arr[i]+=arr[i-1];
		}
		for(int i=2;i<=N;++i){
			for(int j=N;j>=i;--j){
				d[j]=arr[j]-arr[j-i]-min(d[j], d[j-1]);
			}
		}
		cout<<d[N]<<"\n";
	}
	return 0;
}
