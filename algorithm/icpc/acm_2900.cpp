#include<iostream>
using namespace std;
typedef long long ll;
int N, X[1000001], A[1000001];
ll fw[1000001];
void update(int i, int d){
	while(i<=N){
		fw[i]+=(ll)d;
		i+=i&(-i);
	}
}
ll query(int i){
	ll ret=0;
	while(i){
		ret+=fw[i];
		i-=i&(-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int K, Q, l, r, t;
	cin>>N>>K;
	for(int i=0;i<K;++i){
		cin>>t;
		X[t]++;
	}
	for(int i=1;i<N;++i){
		if(X[i]){
			for(int j=0;j<N;j+=i){
				A[j]+=X[i];
			}
		}
		update(i+1, A[i]);
	}
	update(1, A[0]);
	cin>>Q;
	while(Q--){
		cin>>l>>r;
		if(l)	cout<<query(r+1)-query(l)<<"\n";
		else	cout<<query(r+1)<<"\n";
	}
	return 0;
}
