#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, res[100000], cnt=1, p[100000]={-1, };
pii arr[100000];
vector<pii> v;
bool cmp(const pii &a, int b){
	return a.first<b;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr, arr+N);
	int last=0;
	for(int i=0;i<N;++i){
		if(v.empty() || v.back().first<arr[i].second){
			p[i]=v.size() ? v[v.size()-1].second:-1;
			v.push_back({arr[i].second, i});
			last=i;
		}
		else{
			int t=lower_bound(v.begin(), v.end(), arr[i].second, cmp)-v.begin();
			p[i]=t ? v[t-1].second:-1;
			v[t]={arr[i].second, i};
		}
	}
	cout<<N-v.size()<<"\n";
	while(last>-1){
		arr[last].first=-1;
		last=p[last];
	}
	for(int i=0;i<N;++i){
		if(arr[i].first>-1)	cout<<arr[i].first<<"\n";
	}
	return 0;
}
