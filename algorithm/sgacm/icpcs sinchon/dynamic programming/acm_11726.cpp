#include<iostream>
using namespace std;
const int mod=10007;
int main(){
	int n;
	cin>>n;
	int d[n]={1, 2, };
	for(int i=2;i<n;++i){
		d[i]=d[i-1]+d[i-2];
		d[i]%=mod;
	}
	cout<<d[n-1]<<'\n';
	return 0;
}
