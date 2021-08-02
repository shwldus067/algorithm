#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> pii;
pii point[500000];
int N;
int dist(pii a, pii b){
	int dx=a.first-b.first, dy=a.second-b.second;
	return dx*dx+dy*dy;
}
int divide(int s, int e){
	if(e==s)	return 1e9;
	if(e==s+1)	return dist(point[s], point[e]);
	if(e==s+2)	return min({dist(point[s], point[s+1]), dist(point[s], point[e]), dist(point[s+1], point[e])});
	int m=(s+e)/2;
	int l=divide(s, m-1);
	int r=divide(m+1, e);
	int ret=min(l, r);
	int mx=point[m].first, my=point[m].second;
	vector<pii> tmp;
	tmp.push_back({my, mx});
	for(int i=m-1;i>=s;--i){
		int dx=point[i].first-mx;
		if(dx*dx>=ret)	break;
		tmp.push_back({point[i].second, point[i].first});
	}
	for(int i=m+1;i<=e;++i){
		int dx=point[i].first-mx;
		if(dx*dx>=ret)	break;
		tmp.push_back({point[i].second, point[i].first});
	}
	sort(tmp.begin(), tmp.end());
	for(int i=0;i<tmp.size()-1;++i){
		for(int j=i+1;j<tmp.size();++j){
			int dy=tmp[i].first-tmp[j].first;
			if(dy*dy>=ret)	break;
			ret=min(ret, dist(tmp[i], tmp[j]));
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>point[i].first>>point[i].second;
	}
	sort(point, point+N);
	cout<<divide(0, N-1)<<"\n";
	return 0;
}
