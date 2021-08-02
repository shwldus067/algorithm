#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
pair<int, int> per[500000], mask[500000];
bool cmp(pair<int, int> a, pair<int, int> b){
	if(a.second==b.second)	return a.first<b.first;
	return a.second<b.second;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;++i){
		cin>>per[i].first>>per[i].second;
	}
	for(int i=0;i<M;++i){
		cin>>mask[i].first>>mask[i].second;
	}
	sort(per, per+N, cmp);
	sort(mask, mask+M);
	int ans=0;
	for(int i=0, j=0;i<N && j<M;++i){
		int t=mask[j].first;
		if(t>=per[i].first && t<=per[i].second){
			mask[j].second--;
			if(mask[j].second==0)	j++;
			ans++;
		}
		else if(t<per[i].first){
			while(j<M && per)
		}
		else{
			while(j<M && per[i].first>mask[j].first)
				j++;
			if(j==M)	break;
			mask[j].second--;
			if(mask[j].second==0)	j++;
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
