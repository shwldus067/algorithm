#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int N, M;
pll mon[500000], mask[500000];
priority_queue<ll, vector<ll>, greater<ll> > pq;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>mon[i].first>>mon[i].second;
	for(int i=0;i<M;++i)	cin>>mask[i].first>>mask[i].second;
	sort(mon, mon+N);
	sort(mask, mask+M);
	int idx=0, ans=0;
	for(int i=0;i<M;++i){
		while(idx<N && mon[idx].first<=mask[i].first)	pq.push(mon[idx++].second);
		while(pq.size() && pq.top()<mask[i].first)	pq.pop();
		while(pq.size() && mask[i].second--)	pq.pop(), ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
