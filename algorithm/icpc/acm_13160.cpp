#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int N, ans;
pair<int, int> arr[600000];
bool cmp(const pair<int, int> &a, const pair<int, int> &b){
	if(a.first==b.first)	return a.second>b.second;
	return a.first<b.first;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i*2].first;
		arr[i*2].second=i+1;
		cin>>arr[i*2+1].first;
		arr[i*2+1].second=-i-1;
	}
	int M=2*N, cnt=0, pos;
	sort(arr, arr+M, cmp);
	for(int i=0;i<M;++i){
		if(arr[i].second>0){
			cnt++;
			if(ans<cnt){
				ans=cnt;
				pos=i;
			}
		}
		else{
			cnt--;
		}
	}
	cout<<ans<<"\n";
	set<int> S;
	for(int i=0;i<=pos;++i){
		if(arr[i].second>0)	S.insert(arr[i].second);
		else	S.erase(-arr[i].second);
	}
	for(int s:S){
		cout<<s<<" ";
	}
	return 0;
}
