#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t, n;
	long long d[20]={0, 1};
	for(int i=2;i<20;++i){
		d[i]=i*(d[i-1]+d[i-2]);
	}
	cin>>t;
	while(t--){
		cin>>n;
		cout<<d[n-1]<<"\n";
	}
	return 0;
}
