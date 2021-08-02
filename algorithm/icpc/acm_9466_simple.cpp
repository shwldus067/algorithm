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
	int tc, g[100001], w[100001], N, ans, cnt;
	tc=readInt();
	while(tc--){
		N=readInt();
		for(int i=1;i<=N;++i)	w[i]=readInt(), g[i]=0;
		ans=N, cnt=1;
		for(int i=1;i<=N;++i){
			if(g[i])	continue;
			int p=cnt, j=i;
			while(!g[j])	g[j]=cnt++, j=w[j];
			if(g[j]>=p)	ans-=cnt-g[j];
		}
		printf("%d\n", ans);
	}
	return 0;
}
