#include<cstdio>
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
	char cur=read();
	while(cur==10 || cur==32)	cur=read();
	while(cur>=48 && cur<=57){
		sum=sum*10+cur-48;
		cur=read();
	}
	return sum;
}
int main(){
	int N, n, t, k, dp[10000], ans=0;
	N=readInt();
	for(int i=0;i<N;++i){
		t=readInt();n=readInt();
		dp[i]=0;
		while(n--){
			k=readInt()-1;
			if(dp[i]<dp[k])	dp[i]=dp[k];
		}
		dp[i]+=t;
		if(ans<dp[i])	ans=dp[i];
	}
	printf("%d\n", ans);
	return 0;
}
