#include<iostream>
using namespace std;
const int mod=9901;
int main(){
	int N;
	cin>>N;
	int cage[N+1]={1, 3};
	for(int i=2;i<=N;i++){
		cage[i]=2*cage[i-1]+cage[i-2];
		cage[i]%=mod;
	}
	cout<<cage[N]<<"\n";
}
