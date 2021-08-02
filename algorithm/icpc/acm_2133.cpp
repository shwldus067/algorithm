#include<iostream>
using namespace std;
int A[16]={1, 3, }, N;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	if(N&1){
		cout<<"0\n";
		return 0;
	}
	N>>=1;
	for(int i=2;i<=N;++i){
		A[i]=A[i-1]*3;
		for(int j=2;j<=i;++j)	A[i]+=A[i-j]*2;
	}
	cout<<A[N]<<"\n";
	return 0;
}
