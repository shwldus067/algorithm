#include<iostream>
using namespace std;
int N, M, K, cnt[2001];
bool arr[4000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	for(int i=0;i<M;++i){
		int t;
		cin>>t;
		arr[t]=true;
		cnt[t/2000]++;
	}
	while(K--){
		int t;
		cin>>t;
		int ans=0;
		bool chk=false;
		for(int i=t/2000;i<=N/2000 && !chk;++i){
			if(cnt[i]){
				for(int j=i*2000;j<(i+1)*2000;++j){
					if(arr[j] && j>t){
						ans=j;
						chk=true;
						break;
					}
				}
			}
		}
		cnt[ans/2000]--;
		arr[ans]=false;
		cout<<ans<<"\n";
	}
	return 0;
}
