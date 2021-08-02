#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef pair<int, int> pii;
typedef long double ld;
#define PI 3.14159265358979323846
int N, ch[1000], idx, ch1[1000], idx1;
ld L;
pii point[1000];
int ccw(pii &a, pii &b, pii &c){
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}
ld dist(pii &a, pii &b){
	ld x=a.first-b.first, y=a.second-b.second;
	return sqrtl(x*x+y*y);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L;
	for(int i=0;i<N;++i){
		cin>>point[i].first>>point[i].second;
	}
	sort(point, point+N);
	for(int i=0;i<N;++i){
		while(idx>1){
			int ret=ccw(point[ch[idx-2]], point[ch[idx-1]], point[i]);
			if(ret>0)	break;
			idx--;
		}
		ch[idx++]=i;
	}
	for(int i=0;i<N;++i){
		while(idx1>1){
			int ret=ccw(point[ch1[idx1-2]], point[ch1[idx1-1]], point[i]);
			if(ret<0)	break;
			idx1--;
		}
		ch1[idx1++]=i;
	}
	for(int i=idx1-2;i>=0;--i)	ch[idx++]=ch1[i];
	ld ans=0;
	for(int i=1;i<idx;++i){
		ans+=dist(point[ch[i-1]], point[ch[i]]);
	}
	ans+=PI*2*L;
	cout<<round(ans)<<"\n";
	return 0;
}
