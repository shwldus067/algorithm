#include<iostream>
using namespace std;
int arr[200000], pre[200000], mod[100];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int Q, M, a, b, cnt=0, idx=0;
	cin>>Q>>M;
	for(int i=0;i<Q;++i)	pre[i]=-1;
	for(int i=0;i<100;++i)	mod[i]=-1;
	while(Q--){
		cin>>a;
		if(a==1){
			cin>>b;
			arr[idx]=b=b%M;
			if(mod[b]==-1)	cnt++;
			pre[idx]=mod[b];
			mod[b]=idx++;
		}else if(a==2){
			if(idx){
				--idx;
				if(pre[idx]==-1)	cnt--;
				mod[arr[idx]]=pre[idx];
			}
		}else{
			if(cnt==M){
				int ans=1e9;
				for(int i=0;i<M;++i)	ans=min(ans, mod[i]);
				cout<<idx-ans<<"\n";
			}
			else	cout<<"-1\n";
		}
	}
	return 0;
}
