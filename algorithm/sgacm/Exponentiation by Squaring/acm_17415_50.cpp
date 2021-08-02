#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long N, K;
	cin>>N>>K;
	if(K==1){
		cout<<"0\n";
		return 0;
	}
	long long A[N];
	long long B[N], res=0, pre=1;
	for(int i=0;i<N;i++){
		cin>>A[i]>>B[i];
	}
	
	long long pre10[60]={10, };
	long long pre1[60]={1, };
	for(int i=1;i<60;i++){
		pre10[i]=pre10[i-1]*pre10[i-1]%K;
		pre1[i]=(pre1[i-1]+pre1[i-1]*pre10[i-1])%K;
	}
	
	for(int i=N-1;i>=0;i--){
		long long Bi=B[i], ans=0, num10=1;
		int cur=0;
		while(Bi){
			if(Bi&1){
				num10*=pre10[cur];
				num10%=K;
				ans=(ans*pre10[cur])%K+pre1[cur];
				ans%=K;
			}
			Bi>>=1;
			cur++;
		}
		res+=(ans*pre*A[i])%K;
		res%=K;
		pre*=num10;
		pre%=K;
	}
	cout<<res<<"\n";
}
