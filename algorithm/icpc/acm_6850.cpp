#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, ch[10000], idx=2;
pii point[10000];
int ccw(pii &a, pii &b, pii &c){
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}
bool cmp(pii &a, pii &b){
	int ret=ccw(point[0], a, b);
	if(ret==0)	return a<b;
	return ret>0;
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
	swap(point[0], *min_element(point, point+N));
	sort(point+1, point+N, cmp);
	ch[0]=0, ch[1]=1;
	for(int i=2;i<N;++i){
		while(idx>=2){
			int ret=ccw(point[ch[idx-2]], point[ch[idx-1]], point[i]);
			if(ret>0)	break;
			idx--;
		}
		ch[idx++]=i;
	}
	int ans=0;
	for(int i=2;i<idx;++i){
		ans+=ccw(point[0], point[ch[i-1]], point[ch[i]]);
	}
	cout<<ans/100<<"\n";
	return 0;
}
