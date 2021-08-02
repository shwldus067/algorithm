#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int tc, N, tree[75001], cnt;
pii point[75000];
void update(int i){
	while(i<=cnt){
		++tree[i];
		i+=(i&-i);
	}
}
int sum(int i){
	int ret=0;
	while(i>0){
		ret+=tree[i];
		i-=(i&-i);
	}
	return ret;
}
bool cmp(pii &a, pii &b){
	if(a.second==b.second)	return a.first<b.first;
	return a.second>b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tc;
	while(tc--){
		cin>>N;
		for(int i=0;i<N;++i){
			cin>>point[i].second>>point[i].first;
		}
		sort(point, point+N);
		int p=2e9;
		cnt=0;
		for(int i=0;i<N;++i){
			if(p!=point[i].first){
				p=point[i].first;
				++cnt;
			}
			point[i].first=cnt;
		}
		sort(point, point+N, cmp);
		long long ans=0;
		for(int i=0;i<N;++i){
			ans+=1ll*sum(point[i].first);
			update(point[i].first);
		}
		cout<<ans<<"\n";
		++cnt;
		for(int i=1;i<cnt;++i){
			tree[i]=0;
		}
	}
	return 0;
}
