#include<iostream>
using namespace std;
const int mod=1000000000;
int main(){
	int N, K, res=0;
	cin>>N>>K;
	if(K==1){
		cout<<1<<"\n";
		return 0;
	}
	int sum[K-1][N+1];
	for(int i=0;i<=N;i++)	sum[0][i]=1;
	for(int i=1;i<K-1;i++){
		sum[i][0]=1;
		for(int j=1;j<=N;j++){
			sum[i][j]=0;
			for(int k=0;k<=j;k++){
				sum[i][j]+=sum[i-1][k];
				sum[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<=N;i++){
		res+=sum[K-2][i];
		res%=mod;
	}
	cout<<res<<"\n";
	return 0;
}
