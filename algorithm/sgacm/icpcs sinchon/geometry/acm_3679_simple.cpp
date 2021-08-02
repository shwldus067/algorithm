#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int c, n;
pair<pii, int> P[2000];
int ccw(pii a, pii b, pii c){
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c;
	while(c--){
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>P[i].first.first>>P[i].first.second;
			P[i].second=i;
		}
		int ch[2000], top=0;
		bool f[2000]={0, };
		sort(P, P+n);
		for(int i=0;i<n;++i){
			while(top>1){
				if(ccw(P[ch[top-1]].first, P[ch[top-2]].first, P[i].first)>0)
					--top;
				else break;
			}
			ch[top++]=i;
		}
		for(int i=0;i<top;++i)	f[ch[i]]=1;
		for(int i=0;i<n;++i)
			if(!f[i])	cout<<P[i].second<<' ';
		for(int i=n;i>-1;--i)
			if(f[i])	cout<<P[i].second<<' ';
		cout<<"\n";
	}
	return 0;
}
