#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int inf=~(1<<31);
int T, N;
int X[75000], Y[75000];
pair<int, int> point[75000];
bool cmp(pair<int, int> &a, pair<int, int> &b){
	if(a.first==b.first)	return a.second<b.second;
	return a.first>b.first;
}
void update(vector<int> &t, int i){
	while(i<=N){
		t[i]++;
		i+=(i&-i);
	}
}
int query(vector<int> &t, int i){
	int ret=0;
	while(i>0){
		ret+=t[i];
		i-=(i&-i);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		int x, y;
		for(int i=0;i<N;++i){
			X[i]=Y[i]=i;
			cin>>point[i].first>>point[i].second;
		}
		sort(X, X+N, [](int i, int j){
			if(point[i].first==point[j].first)	return point[i].second>point[j].second;
			return point[i].first<point[j].first;
		});
		sort(Y, Y+N, [](int i, int j){
			return point[i].second>point[j].second;
		});
		int xp=-inf, xc=0, yp=-inf, yc=0;
		for(int i=0;i<N;++i){
			if(point[X[i]].first!=xp)	xc++;
			if(point[Y[i]].second!=yp)	yc++;
			xp=point[X[i]].first, yp=point[Y[i]].second;
			point[X[i]].first=xc;
			point[Y[i]].second=yc;
		}
		vector<int> tree(N+1, 0);
		long long ans=0;
		for(int i=0;i<N;++i){
			ans+=1ll*query(tree, point[X[i]].second);
			update(tree, point[X[i]].second);
		}
		cout<<ans<<"\n";
	}
}
