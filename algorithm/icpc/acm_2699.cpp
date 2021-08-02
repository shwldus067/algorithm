#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int P, N;
pii point[50];
int ch[50], idx;
bool cmp(pii &a, pii &b){
	if(a.second==b.second)	return a.first<b.first;
	return a.second>b.second;
}
int ccw(pii &a, pii &b, pii &c){
	return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}
bool comp(pii &a, pii &b){
	int ret=ccw(point[0], a, b);
	if(ret==0){
		if(a.second==b.second)	return a.first<b.first;
		return a.second>b.second;
	}
	return ret<0;
}
void graham_scan(){
	ch[0]=0;
	ch[1]=1;
	idx=2;
	for(int i=2;i<N;++i){
		while(idx>=2){
			int ret=ccw(point[ch[idx-2]], point[ch[idx-1]], point[i]);
			if(ret<0)	break;
			idx--;
		}
		ch[idx++]=i;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>P;
	while(P--){
		cin>>N;
		for(int i=0;i<N;++i){
			cin>>point[i].first>>point[i].second;
		}
		swap(point[0], *min_element(point, point+N, cmp));
		sort(point+1, point+N, comp);
		graham_scan();
		cout<<idx<<"\n";
		for(int i=0;i<idx;++i){
			cout<<point[ch[i]].first<<" "<<point[ch[i]].second<<"\n";
		}
	}
	return 0;
}
