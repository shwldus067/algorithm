#include<iostream>
#include<algorithm>
using namespace std;
int K, N, m=2e9, ans;
pair<int, int> arr[1000000];
int dist[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>K>>N;
	int l=0, r=0;
	for(int i=0;i<N;++i){
		cin>>arr[i].first>>arr[i].second;
	}
	sort(arr, arr+N);
	int cnt=0;
	while(r<N){
		cnt+=!dist[arr[r++].second]++;
		while(cnt==K){
			int tmp=(arr[r-1].first-arr[l].first+1)/2;
			if(tmp<m){
				m=tmp;
				ans=arr[r-1].first-tmp;
			}
			cnt-=!--dist[arr[l++].second];
		}
	}
	cout<<ans<<"\n";
	return 0;
}
