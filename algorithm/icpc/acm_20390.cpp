#include<iostream>
using namespace std;
#define inf 1e13
typedef __int128 li;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, a, b, cnt=0, cur;
	li tp=1;
	ll A, B, C, D, X[10000], Y[10000], ans=0, cost;
	bool chk[10000]={0, };
	cin>>N>>A>>B>>C>>D;
	for(int i=0;i<N;++i)	cin>>X[i], Y[i]=inf;
	Y[0]=0;
	for(int n=0;n<N;++n){
		cost=inf;
		for(int i=0;i<N;++i){
			if(!chk[i] && Y[i]<cost)	cur=i, cost=Y[i];
		}
		chk[cur]=1;
		ans+=cost;
		for(int i=0;i<N;++i){
			if(chk[i])	continue;
			a=min(cur, i), b=max(cur, i);
			ll dist=(ll)(((tp*X[a]*A%C+tp*X[b]*B%C)%C)^D);
			Y[i]=min(Y[i], dist);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
