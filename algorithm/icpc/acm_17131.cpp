#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
const long long mod=1e9+7;
const int M=4e5+1;
int N;
pii star[200000];
int tree[400002];
void update(int i, int d){
	while(i<=M){
		tree[i]+=d;
		i+=(i&-i);
	}
}
int sum(int i){
	int ret=0;
	while(i>0){
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}
bool cmp(const pii &a, const pii &b){
	return a.first<b.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>star[i].second>>star[i].first;
		star[i].second+=2e5+1;
		update(star[i].second, 1);
	}
	sort(star, star+N);
	long long ans=0;
	int x=1e6, cnt=0;
	for(int i=0;i<N;++i){
		if(x!=star[i].first){
			x=star[i].first;
			for(int j=i;j<N && star[j].first==x;++j){
				update(star[j].second, -1);
				cnt++;
			}
		}
		int a=sum(star[i].second-1);
		int b=N-cnt-sum(star[i].second);
		ans=(ans+1ll*a*b)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
