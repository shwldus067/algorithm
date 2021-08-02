#include<cstdio>
using namespace std;
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
	int t, n, tp;
	int cnt[1000];
	t=readInt();
	while(t--){
		n=readInt();
		for(int i=0;i<n;++i)	cnt[i]=0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				tp=readInt();
				if(tp){
					cnt[i]++;
					cnt[j]++;
				}
			}
		}
		int ans=0;
		for(int i=0;i<n;++i)	ans+=cnt[i]*(n-1-cnt[i]);
		printf("%d\n", n*(n-1)*(n-2)/6-ans/2);
	}
	return 0;
}
