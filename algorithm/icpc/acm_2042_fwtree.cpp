#include<iostream>
using namespace std;
typedef long long ll;
ll N, M, K;
ll tree[1000001], arr[1000001];
void update(int i, ll x){
	while(i<=N){
		tree[i]+=x;
		i+=i&(-i);
	}
}
ll sum(int i){
	ll ret=0;
	while(i){
		ret+=tree[i];
		i-=i&(-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	ll a, b, c;
	for(int i=0;i<N;++i){
		cin>>a;
		update(i+1, a);
		arr[i+1]=a;
	}
	M+=K;
	while(M--){
		cin>>a>>b>>c;
		if(a==1){
			update(b, c-arr[b]);
			arr[b]=c;
		}else{
			cout<<sum(c)-sum(b-1)<<"\n";
		}
	}
	return 0;
}
