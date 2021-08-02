#include<iostream>
using namespace std;
int N, S, M, m, t;
long long sum[8000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>S;
	cin>>t;
	sum[t+4000000]=1;
	M=m=t+4000000;
	for(int i=1;i<N;i++){
		cin>>t;
		if(t<0){
			for(int j=m;j<=M;j++){
				sum[j+t]+=sum[j];
			}
		}
		else{
			for(int j=M;j>=m;j--){
				sum[j+t]+=sum[j];
			}
		}
		sum[t+4000000]++;
		if(t<0){
			m=m+t<t+4000000 ? m+t:t+4000000;
			M=M>t+4000000 ? M:t+4000000;
		}
		else{
			m=m<t+4000000 ? m:t+4000000;
			M=M+t>t+4000000 ? M+t:t+4000000;
		}
	}
	cout<<sum[S+4000000]<<"\n";
	return 0;
}
