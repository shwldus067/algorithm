#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
ll gcd(ll u, ll v){
	ll t;
	if(u<v)	t=u, u=v, v=t;
	while(v)	t=u%v,u=v,v=t;
	return u;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	ll N, a[10], b[10];
	ll p[10], q[10], g;
	ll L[10]={1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	vector<int> ratio[10];
	cin>>N;
	for(int i=0;i<N-1;++i){
		cin>>a[i]>>b[i]>>p[i]>>q[i];
		g=gcd(p[i], q[i]);
		p[i]/=g;q[i]/=g;
		ratio[a[i]].push_back(i);
		ratio[b[i]].push_back(i);
		L[a[i]]*=p[i]/gcd(L[a[i]], p[i]);
		L[b[i]]*=q[i]/gcd(L[b[i]], q[i]);
	}
	for(int i=0;i<N;++i){
		queue<int> Q;
		Q.push(i);
		while(Q.size()){
			int cur=Q.front();Q.pop();
			int t=0;
			ll x, y;
			for(int v:ratio[cur]){
				x=L[a[v]]*q[v];y=L[b[v]]*p[v];
				g=gcd(x, y);
				if(g!=y || g!=x){
					t=1;
					L[a[v]]*=y/g;
					L[b[v]]*=x/g;
				}
			}
			if(t){
				for(int v:ratio[cur]){
					if(a[v]==cur)	Q.push(b[v]);
					else	Q.push(a[v]);
				}
			}
		}
	}
	for(int i=0;i<N;++i)	cout<<L[i]<<" ";
	return 0;
}
