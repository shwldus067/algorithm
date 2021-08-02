#include<iostream>
using namespace std;
typedef long long ll;
const int MAX=65537;
int N, K, M, arr[250000], tree[65538];
void update(int i, int d){
	while(i<=MAX){
		tree[i]+=d;
		i+=(i&-i);
	}
}
ll query(int i){
	ll ret=0;
	while(i>0){
		ret+=(ll)tree[i];
		i-=(i&-i);
	}
	return ret;
}
int midval(){
	int s=1, e=MAX;
	while(s<e){
		int m=(s+e)/2;
		if(query(m)<M)	s=m+1;
		else	e=m;
	}
	return s-1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;++i)	cin>>arr[i];
	for(int i=0;i<K;++i){
		update(arr[i]+1, 1);
	}
	M=(K+1)/2;
	ll ans=midval();
	for(int i=0;i<N-K;++i){
		update(arr[i]+1, -1);
		update(arr[i+K]+1, 1);
		ans+=midval();
	}
	cout<<ans<<"\n";
	return 0;
}
