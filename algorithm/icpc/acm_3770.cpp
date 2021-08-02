#include<iostream>
#include<algorithm>
using namespace std;
int T, N, M, K;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	for(int t=1;t<=T;++t){
		cin>>N>>M>>K;
		pair<int, int> way[K+1];
		int tree[M+1]={0, };
		for(int k=K;k>0;--k){
			cin>>way[k].first>>way[k].second;
		}
		sort(way+1, way+K+1);
		long long ans=0;
		int j=way[K].second;
		while(j<=M){
			++tree[j];
			j+=(j&-j);
		}
		for(int k=K-1;k>0;--k){
			int tmp=0, i=way[k].second-1;
			while(i){
				tmp+=tree[i];
				i-=(i&-i);
			}
			ans+=(long long)tmp;
			i=way[k].second;
			while(i<=M){
				++tree[i];
				i+=(i&-i);
			}
		}
		cout<<"Test case "<<t<<": "<<ans<<"\n";
	}
	return 0;
}
