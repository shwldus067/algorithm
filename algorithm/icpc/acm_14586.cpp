#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, dp[301];
pair<ll, ll> dom[301];
int main(){
	scanf("%d", &N);
	for(int i=1;i<=N;++i) scanf("%d %d", &dom[i].first, &dom[i].second), dp[i]=500;
	sort(dom+1, dom+N+1);
	for(int i=1;i<=N;++i){
		ll l=dom[i].first-dom[i].second;
		ll r=dom[i].first+dom[i].second;
		int t=i;
		while(1){
			if(t<=0)	break;
			if(l>dom[t].first){
				break;
			}
			l=min(l, dom[t].first-dom[t].second);
			--t;
		}
		if(t<=0)	dp[i]=1;
		else	dp[i]=min(dp[i], 1+dp[t]);
		t=i;
		while(1){
			if(t>N)	break;
			if(r<dom[t].first){
				break;
			}
			r=max(r, dom[t].first+dom[t].second);
			++t;
		}
		dp[t-1]=min(dp[t-1], dp[i-1]+1);
	}
	printf("%d\n", dp[N]);
	return 0;
}
