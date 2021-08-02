#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N, pdx;
pii point[100000];
ll ccw(pii &a, pii &b, pii &c){
	return 1ll*(b.first-a.first)*(c.second-a.second)-1ll*(b.second-a.second)*(c.first-a.first);
}
bool comp(pii &a, pii &b){
	ll ret=ccw(point[0], a, b);
	if(ret==0){
		if(a.first==b.first)	return a.second>b.second;
		return a.first>b.first;
	}
	return ret>0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int x, y;
		cin>>x>>y;
		char c;
		cin>>c;
		if(c=='Y')	point[pdx++]={x, y};
	}
	swap(point[0], *min_element(point, point+pdx));
	sort(point+1, point+pdx, comp);
	cout<<pdx<<"\n";
	int i=1;
	cout<<point[0].first<<" "<<point[0].second<<"\n";
	while(i+1<N && ccw(point[i-1], point[i], point[i+1])==0){
		++i;
	}
	for(int k=i;k>0;--k){
		cout<<point[k].first<<" "<<point[k].second<<"\n";
	}
	for(++i;i<pdx;++i){
		cout<<point[i].first<<" "<<point[i].second<<"\n";
	}
	return 0;
}
