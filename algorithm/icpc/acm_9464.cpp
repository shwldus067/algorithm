#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int T, L;
set<pii> S;
vector<pii> V;
int gcd(int a, int b){
	int c;
	while(b){
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}
bool cmp(const pii& a, const pii& b){
	return a.first+a.second<b.first+b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y;
	for(y=1;y<500;++y){
		for(x=y+1;x<500;++x){
			int a=2*x*y, b=x*x-y*y, c;
			if(a<b){
				c=a, a=b, b=c;
			}
			c=gcd(a, b);
			a/=c, b/=c;
			S.insert({a, b});
		}
	}
	set<pii>::iterator it;
	int i;
	V=vector<pii>(S.size());
	for(i=0, it=S.begin();it!=S.end();++it, ++i){
		V[i]={it->first, it->second};
	}
	sort(V.begin(), V.end(), cmp);
	cin>>T;
	while(T--){
		cin>>L;
		int ans=0;
		for(int i=0;i<V.size();++i){
			int tmp=2*(V[i].first+V[i].second);
			if(L>=tmp){
				L-=tmp;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
