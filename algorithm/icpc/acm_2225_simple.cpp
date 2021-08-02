#include<iostream>
using namespace std;
const int mod=1000000000;
int main(){
	int N, K;
	cin>>N>>K;
	if(K==1){
		cout<<1<<"\n";
		return 0;
	}
	int sum[N+1];
	for(int i=0;i<=N;i++)	sum[i]=1;
	for(int i=2;i<=K;i++){
		int cur=0;
		for(int j=0;j<=N;j++){
			cur+=sum[j];
			cur%=mod;
			sum[j]=cur;
		}
	}
	cout<<sum[N]<<"\n";
	return 0;
}
