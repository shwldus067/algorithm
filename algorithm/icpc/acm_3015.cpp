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
int cnt[500001];
int main(){
	int N, st[500001], t=1, a;
	long long ans=0;
	N=readInt();
	st[1]=readInt();
	cnt[1]=0;
	while(--N){
		a=readInt();
		int p=t;
		while(t && st[t]<a)	--t, ++ans;
		if(st[t]==a){
			ans+=cnt[t]+1;
		}
		else{
			if(p==t || t)	++ans;
		}
		if(st[t]==a)	cnt[t+1]=cnt[t]+1;
		else if(t)	cnt[t+1]=1;
		else	cnt[t+1]=0;
		st[++t]=a;
	}
	printf("%lld\n", ans);
	return 0;
}
