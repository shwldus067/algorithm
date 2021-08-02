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
inline int min(int a, int b){return a<b?a:b;}
int A[1000001], p[1000001], seg[1<<21], base=1<<20;
void update(int i, int d){
	i+=base;
	seg[i]=d;
	for(i>>=1;i;i>>=1){
		int j=i*2;
		seg[i]=min(seg[j], seg[j+1]);
	}
}
int main(){
	int Q, mod, a, b, cnt=0, idx=0;
	Q=readInt();mod=readInt();
	if(mod>Q){
		while(Q--){
			a=readInt();
			if(a==1)	a=readInt();
			else if(a==3)	printf("-1\n");
		}
		return 0;
	}
	for(int i=1;i<base*2;++i)	seg[i]=1e9;
	while(Q--){
		a=readInt();
		if(a==1){
			b=readInt();
			A[++idx]=b=b%mod;
			if(seg[b+base]==1e9)	++cnt, p[idx]=0;
			else	p[idx]=seg[b+base];
			update(b, idx);
		}else if(a==2){
			if(idx){
				if(!p[idx])	--cnt, update(A[idx], 1e9);
				else	update(A[idx], p[idx]);
				--idx;
			}
		}else{
			if(cnt<mod)	printf("-1\n");
			else	printf("%d\n", idx+1-seg[1]);
		}
	}
	return 0;
}
