#include<iostream>
using namespace std;
typedef pair<long long, long long> pii;
typedef long long ll;
int tc;
pii line[2], box[5];
int ccw(pii &a, pii &b, pii &c){
	long long ret=1ll*(b.first-a.first)*(c.second-a.second)-1ll*(b.second-a.second)*(c.first-a.first);
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	return -1;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>tc;
	while(tc--){
		cin>>line[0].first>>line[0].second>>line[1].first>>line[1].second;
		cin>>box[0].first>>box[0].second>>box[2].first>>box[2].second;
		ll t;
		if(box[0].first>box[2].first)
			t=box[0].first, box[0].first=box[2].first, box[2].first=t;
		if(box[0].second>box[2].second)
			t=box[0].second, box[0].second=box[2].second, box[2].second=t;
		box[1]={box[0].first, box[2].second};
		box[3]={box[2].first, box[0].second};
		box[4]=box[0];
		if(line[0]>line[1])	swap(line[0], line[1]);
		ll my, My;
		if(line[0].second>line[1].second)	my=line[1].second, My=line[0].second;
		else	my=line[0].second, My=line[1].second;
		if(box[0].first<=line[0].first && line[1].first<=box[2].first
		 && box[0].second<=my && My<=box[2].second){
			cout<<"T\n";
			continue;
		}
		int f=0;
		for(int i=0;i<4;++i){
			int p=ccw(line[0], line[1], box[i]), q=ccw(line[0], line[1], box[i+1]);
			int r=ccw(box[i], box[i+1], line[0]), s=ccw(box[i], box[i+1], line[1]);
			if(p==0 && q==0 && r==0 && s==0){
				pii x, y;
				if(box[i]>box[i+1])	x=box[i+1], y=box[i];
				else	x=box[i], y=box[i+1];
				if(x<=line[1] && line[0]<=y){
					f=1;
					break;
				}
			}
			else if(p*q<=0 && r*s<=0){
				f=1;
				break;
			}
		}
		if(f)	cout<<"T\n";
		else	cout<<"F\n";
	}
	return 0;
}
