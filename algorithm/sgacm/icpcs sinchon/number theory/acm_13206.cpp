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
		for(int j=i*i;j<1001;j+=i*2){
			chk[j]=true;
		}
	}
	cin>>T;
	while(T--){
		cin>>N;
		int ans=1, t;
		int res[pcnt]={0, }, rcnt[pcnt]={0, };
		for(int i=0;i<N;++i){
			cin>>t;
			for(int j=0;j<pcnt && t>1;++j){
				int mul=1, cnt=0;
				while(t%prime[j]==0){
					cnt++;
					mul=1ll*mul*prime[j]%mod;
					t/=prime[j];
				}
				if(rcnt[j]<cnt){
					rcnt[j]=cnt;
					res[j]=mul;
				}
			}
		}
		for(int i=0;i<pcnt;++i){
			if(res[i]){
				ans=1ll*ans*res[i]%mod;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
