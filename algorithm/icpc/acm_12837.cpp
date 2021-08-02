#include<iostream>
using namespace std;
typedef long long ll;
int N, Q;
ll tree[1000001];
void update(int i, ll d){
	while(i<=N){
		tree[i]+=d;
		i+=(i&-i);
	}
}
ll query(int i){
	ll ret=0;
	while(i){
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>Q;
	while(Q--){
		int a, b, c;
		cin>>a>>b>>c;
		if(a==1){
			update(b, (ll)c);
		}
		else{
			cout<<query(c)-query(b-1)<<"\n";
		}
	}
	return 0;
}
