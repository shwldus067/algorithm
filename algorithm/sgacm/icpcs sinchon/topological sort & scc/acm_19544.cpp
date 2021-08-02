#include<iostream>
#include<vector>
using namespace std;
const int mod=1000000007;
typedef long long ll;
int N, cnt[500];
ll fact[501]={1, };
int arr[500][500], cyclen[500];
vector<vector<int> > cycle;
int tree[500];
ll cal(ll a, ll b){
	ll ret=1;
	while(b){
		if(b&1)	ret=(ret*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=1;i<=N;++i){
		fact[i]=(fact[i-1]*i)%mod;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			int t;
			cin>>t;
			if(t){
				arr[i][j]=t;
				cnt[i]++;
			}
		}
	}
	for(int i=0;i<N;++i){
		for(int j=i+1;j<N;++j){
			if(arr[i][j] && arr[j][i]){
				if(cyclen[i]==0 && cyclen[j]==0){
					cycle.push_back(vector<int>());
					int idx=cyclen[i]=cyclen[j]=cycle.size();
					idx--;
					cycle[idx].push_back(i);
					cycle[idx].push_back(j);
				}
				else if(cyclen[j]==0){
					cyclen[j]=cyclen[i];
					cycle[cyclen[i]-1].push_back(j);
				}
			}
		}
	}
	for(int i=0;i<cycle.size();++i){
		int cur=cycle[i][0];
		for(int j=0;j<N;++j){
			if(cyclen[j]==0 && arr[j][cur]){
				if(cnt[j]-1==cycle[i].size()){
					tree[i]++;
				}
			}
		}
	}
	ll ans=1;
	for(int i=0;i<cycle.size();++i){
		ans=(ans*fact[cycle[i].size()-1])%mod;
		ans=(ans*cal(cycle[i].size(), tree[i]))%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
