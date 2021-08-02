#include<iostream>
using namespace std;
const long long mod=1000000007;
int T, N, prime[200]={2, }, pcnt=1;
bool chk[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=3;i<1001;i+=2){
		if(chk[i])	continue;
		prime[pcnt++]=i;
		for(int j=i*i;j<1001;j+=i+i){
			chk[j]=true;
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		int ans=1, t;
		int rcnt[1001]={0, };
		bool bef[1001]={0, };
		for(int i=0;i<N;++i){
			cin>>t;
			if(bef[t])	continue;
			bef[t]=true;
			for(int j=0;j<pcnt && t>=prime[j]*prime[j];++j){
				int cnt=0, p=prime[j];
				while(t%p==0){
					cnt++;
					t/=p;
				}
				if(rcnt[p]<cnt){
					rcnt[p]=cnt;
				}
			}
			if(t>1 && rcnt[t]<1)	rcnt[t]=1;
		}
		for(int i=0;i<pcnt;++i){
			int p=prime[i];
			for(int j=0;j<rcnt[p];++j){
				ans=1ll*ans*p%mod;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
