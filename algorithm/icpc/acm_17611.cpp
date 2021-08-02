#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N;
pii line[2][100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t=0, x[2], y[2], fx, fy;
	int cnt[2]={0, 0};
	cin>>fx>>fy;
	x[0]=fx, y[0]=fy;
	for(int i=1;i<N;++i){
		t^=1;
		cin>>x[t]>>y[t];
		if(x[0]==x[1]){
			if(y[0]<y[1])
				line[0][cnt[0]++]={y[0], 1}, line[0][cnt[0]++]={y[1], -1};
			else
				line[0][cnt[0]++]={y[1], 1}, line[0][cnt[0]++]={y[0], -1};
		}
		else{
			if(x[0]<x[1])
				line[1][cnt[1]++]={x[0], 1}, line[1][cnt[1]++]={x[1], -1};
			else
				line[1][cnt[1]++]={x[1], 1}, line[1][cnt[1]++]={x[0], -1};
		}
	}
	if(fx==x[t]){
		if(fy<y[t])
			line[0][cnt[0]++]={fy, 1}, line[0][cnt[0]++]={y[t], -1};
		else
			line[0][cnt[0]++]={y[t], 1}, line[0][cnt[0]++]={fy, -1};
	}
	else{
		if(fx<x[t])
			line[1][cnt[1]++]={fx, 1}, line[1][cnt[1]++]={x[t], -1};
		else
			line[1][cnt[1]++]={x[t], 1}, line[1][cnt[1]++]={fx, -1};
	}
	sort(&(line[0][0]), &(line[0][0])+cnt[0]);
	sort(&(line[1][0]), &(line[1][0])+cnt[1]);
	int ans=0;
	for(int k=0;k<2;++k){
		int d=0;
		for(int i=0;i<cnt[k];++i){
			d+=line[k][i].second;
			ans=max(ans, d);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
