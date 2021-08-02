#include<iostream>
#include<algorithm>
using namespace std;
int T, n, k;
pair<int, int> p[10000];
bool sol(int mid){
	int m=k, tmp, a=p[0].second, b=a;
	for(int i=1;i<n;++i){
		a=min(a, p[i].second);
		b=max(b, p[i].second);
		if(mid<b-a){
			m--;
			a=p[i].second, b=a;
		}
	}
	if(m<=0)	return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>k;
		int a, b;
		for(int i=0;i<n;++i){
			cin>>a>>b;
			p[i]={a, b};
		}
		sort(p, p+n);
		int l=0, r=2e8;
		while(l<r){
			int m=(l+r)/2;
			if(sol(m))	r=m;
			else	l=m+1;
		}
		if(r&1)	cout<<r/2<<".5\n";
		else	cout<<r/2<<".0\n";
	}
}
