#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int N, ans;
pii arr[600000];
int start[300000], to[300000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int s, e;
	for(int i=0;i<N;++i){
		cin>>s>>e;
		start[i]=s, to[i]=e;
		arr[i]={s, -1};
		arr[i+N]={e, 1};
	}
	int M=2*N;
	sort(arr, arr+M);
	int cnt=0, pos;
	for(int i=0;i<M;++i){
		cnt+=-arr[i].second;
		if(cnt>ans){
			ans=cnt;
			pos=arr[i].first;
		}
	}
	cout<<ans<<"\n";
	for(int i=0;i<N;++i){
		if(start[i]<=pos && pos<=to[i]){
			cout<<i+1<<" ";
		}
	}
	return 0;
}
