#include<iostream>
using namespace std;
int N, M, t[10001], cnt[31];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;++i){
		cin>>t[i];
		cnt[t[i]]++;
	}
	if(N<=M){
		cout<<N<<"\n";
		return 0;
	}
	long long l=0, r=6e10, ti=0, tmp;
	while(l<=r){
		long long mid=(l+r)/2;
		tmp=M;
		for(int i=1;i<=30;++i){
			tmp+=(mid/i)*cnt[i];
		}
		if(tmp<N)	l=mid+1;
		else	r=mid-1, ti=mid;
	}
	tmp=M;
	for(int i=0;i<M;++i)	tmp+=(ti-1)/t[i];
	int ans=0;
	for(;ans<M;++ans){
		if(ti%t[ans]==0)	tmp++;
		if(tmp==N)	break;
	}
	cout<<ans+1<<"\n";
	return 0;
}
