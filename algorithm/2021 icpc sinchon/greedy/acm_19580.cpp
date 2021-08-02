#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
multimap<ll, ll> mask;
struct str{
	ll l, r;
	bool const operator<(const str &a)const{
		if(a.r==r)	return	l>a.l;
		return r<a.r;
	}
}mon[500000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	cin>>N>>M;
	for(int i=0;i<N;++i)	cin>>mon[i].l>>mon[i].r;
	for(int i=0;i<M;++i){
		ll p, x;
		cin>>p>>x;
		mask.insert({p, x});
	}
	sort(mon, mon+N);
	int ans=0;
	for(int i=0;i<N;++i){
		multimap<ll, ll>::iterator it=mask.lower_bound(mon[i].l);
		if(it!=mask.end() && it->first<=mon[i].r){
			it->second--;ans++;
			if(it->second==0)	mask.erase(it);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
