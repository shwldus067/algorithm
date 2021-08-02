#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, ch1[10000], ch2[10000], idx1, idx2;
pii point[10000];
int ccw(pii &a, pii &b, pii &c){
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>point[i].first>>point[i].second;
	}
	if(N<3){
		cout<<"0\n";
		return 0;
	}
	sort(point, point+N);
	for(int i=0;i<N;++i){
		while(idx1>1){
			int ret=ccw(point[ch1[idx1-2]], point[ch1[idx1-1]], point[i]);
			if(ret>0)	break;
			idx1--;
		}
		ch1[idx1++]=i;
	}
	for(int i=0;i<N;++i){
		while(idx2>1){
			int ret=ccw(point[ch2[idx2-2]], point[ch2[idx2-1]], point[i]);
			if(ret<0)	break;
			idx2--;
		}
		ch2[idx2++]=i;
	}
	for(int i=idx2-2;i>0;--i){
		ch1[idx1++]=ch2[i];
	}
	int ans=0;
	for(int i=2;i<idx1;++i){
		ans+=ccw(point[0], point[ch1[i-1]], point[ch1[i]]);
	}
	cout<<ans/100<<"\n";
	return 0;
}
