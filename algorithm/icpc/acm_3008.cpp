#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int N, x[1500], y[1500];
int gcd(int a, int b){
	while(b){
		int c=b;
		b=a%b;
		a=c;
	}
	return a;
}
struct grad{
	int a, b;
	grad(){}
	grad(int p, int q){
		if(p<0)	p=-p,q=-q;
		int g=gcd(abs(p), abs(q));
		a=p/g, b=q/g;
	}
	bool operator<(const grad& gd)const{
		return (ll)gd.a*b<(ll)gd.b*a;
	}
	bool operator()(const grad& gd){
		return (ll)gd.a*b<(ll)gd.b*a;
	}
};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>x[i]>>y[i];
	struct grad g[1500], tmp;
	int ans=0;
	for(int i=0;i<N;++i){
		int h=0, v=0, idx=0;
		for(int j=0;j<N;++j){
			if(i==j)	continue;
			int dx=x[i]-x[j], dy=y[i]-y[j];
			if(!dx)	++v;
			else if(!dy)	++h;
			else	g[idx++]=grad(dx, dy);
		}
		sort(g, g+idx);
		for(int k=0;k<idx;++k){
			tmp=grad(g[k].b, -g[k].a);
			if(tmp.b<0)	break;
			ans+=(upper_bound(g, g+idx, tmp)-g)-(lower_bound(g, g+idx, tmp)-g);
		}
		ans+=h*v;
	}
	cout<<ans<<"\n";
	return 0;
}
