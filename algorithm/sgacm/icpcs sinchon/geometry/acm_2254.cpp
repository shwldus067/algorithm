#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N;
pii p;
vector<pii> point;
vector<int> convex_hull;
int ccw(pii a, pii b, pii c){
	int x1=b.first-a.first, x2=c.first-a.first;
	int y1=b.second-a.second, y2=c.second-a.second;
	ll ret=1ll*x1*y2-1ll*x2*y1;
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	else return -1;
}
bool cmp(pii &a, pii &b){
	int ret=ccw(point[0], a, b);
	if(ret==0){
		return a.first==b.first ? a.second<b.second : a.first<b.first;
	}
	else return ret==1;
}
void graham_scan(){
	convex_hull.clear();
	convex_hull.push_back(0);
	convex_hull.push_back(1);
	for(int i=2;i<point.size();++i){
		while(convex_hull.size()>=2){
			int p2=convex_hull.back();
			convex_hull.pop_back();
			int p1=convex_hull.back();
			if(ccw(point[p1], point[p2], point[i])==1){
				convex_hull.push_back(p2);
				break;
			}
		}
		convex_hull.push_back(i);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>p.first>>p.second;
	point.resize(N);
	for(int i=0;i<N;++i){
		int x, y;
		cin>>x>>y;
		point[i]={x, y};
	}
	int ans=0;
	while(1){
		if(point.size()<3)	break;
		swap(point[0], *min_element(point.begin(), point.end()));
		sort(point.begin()+1, point.end(), cmp);
		graham_scan();
		bool flag=false;
		int res=ccw(p, point[convex_hull[0]], point[convex_hull.back()]);
		for(int i=1;i<convex_hull.size();++i){
			int tmp=ccw(p, point[convex_hull[i-1]], point[convex_hull[i]]);
			if(res*tmp>=0){
				flag=true;
				break;
			}
		}
		if(flag)	break;
		for(int i:convex_hull)	point[i].first=1e9;
		vector<pii> npoint(N-convex_hull.size());
		int idx=0;
		for(pii &pt:point){
			if(pt.first!=1e9)	npoint[idx++]=pt;
		}
		point=npoint;
		++ans;
	}
	cout<<ans<<"\n";
	return 0;
}
