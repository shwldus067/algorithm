#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
int Z, N, tw[200000], len[200000], rlen[200000], base;
int seg[1<<19];	//k번째 값으로 시작하는 연속한 증가하는 배열 길이 
pii rev[200000];
void update(int idx, int d){
	int i=idx+base;
	seg[i]=max(seg[i], d);
	for(i=i>>1;i;i>>=1){
		int j=i*2;
		seg[i]=max(seg[j], seg[j+1]);
	}
}
int query(int l){
	int ret=0;
	int r=N+base-1;
	l+=base;
	while(l<=r){
		if(l&1)	ret=max(ret, seg[l++]);
		if(~r&1)	ret=max(ret, seg[r--]);
		l>>=1, r>>=1;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>Z;
	while(Z--){
		cin>>N;
		for(int i=0;i<N;++i)	cin>>tw[i];
		base=1;
		while(base<N)	base*=2;
		memset(seg, 0, base*2*sizeof(int));
		len[0]=1;
		for(int i=1;i<N;++i){
			if(tw[i]>tw[i-1])	len[i]=len[i-1]+1;
			else	len[i]=1;
		}
		rev[N-1]={tw[N-1], 1};
		rlen[N-1]=1;
		for(int i=N-2;i>=0;--i){
			if(tw[i]<tw[i+1])	rev[i]={tw[i], rlen[i+1]+1};
			else	rev[i]={tw[i], 1};
			rlen[i]=rev[i].second;
		}
		sort(rev, rev+N);
		for(int i=0;i<N;++i)	tw[i]=lower_bound(rev, rev+N, (pii){tw[i], 0})-rev;
		int ans=0;
		for(int i=N-1;i>=0;--i){
			ans=max(ans, len[i]+query(tw[i]+1));
			update(tw[i], rlen[i]);
		}
		cout<<ans<<"\n";
	}
	return 0; 
}
