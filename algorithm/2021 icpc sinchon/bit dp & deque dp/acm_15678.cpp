#include<cstdio>
using namespace std;
typedef long long ll;
inline ll max(ll a, ll b){return a<b?b:a;}
char buf[1<<17];
inline char read(){
	static int idx=1<<17;
	if(idx==1<<17){
		fread(buf, 1, 1<<17, stdin);
		idx=0;
	}
	return buf[idx++];
}
inline int readInt(){
	int sum=0;
	bool f=0;
	char cur=read();
	while(cur!='-' && (cur==10 || cur==32))	cur=read();
	if(cur=='-')	f=1, cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	if(f)	sum=-sum;
	return sum;
}
int main(){
	int N, D, dq[100000], s=0, e=0;
	ll dp[100000], ans=-1e18;
	N=readInt();D=readInt();
	for(int i=0;i<N;++i){
		if(s<e && dq[s]<i-D)	++s;
		dp[i]=(ll)readInt();
		if(s<e)	dp[i]+=max(0ll, dp[dq[s]]);
		ans=max(ans, dp[i]);
		while(s<e && dp[dq[e-1]]<dp[i])	--e;
		dq[e++]=i;
	}
	printf("%lld\n", ans);
	return 0;
}
