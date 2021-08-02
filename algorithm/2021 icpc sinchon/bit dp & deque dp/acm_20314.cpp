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
int h[200000], t[200000], l[200000], d[200000];
int main(){
	int N, T, s=0, e=0, idx=0;
	N=readInt();
	for(int i=0;i<N;++i)	h[i]=readInt();
	for(int i=1;i<N;++i)	t[i]=readInt(), t[i]+=t[i-1];
	for(int i=0;i<N;++i){
		while(s<e && d[s]<i)	++s;
		while(idx<N && t[idx]-t[i]<=h[idx]){
			while(s<e && h[idx]>h[d[e-1]])	--e;
			d[e++]=idx++;
		}
		l[i]=h[d[s]];
	}
	T=t[N-1];
	for(int i=0;i<N;++i)	t[i]=T-t[i];
	s=e=0;
	idx=N-1;
	for(int i=N-1;i;--i){
		while(s<e && d[s]>i)	++s;
		while(idx>=0 && t[idx]-t[i]<=h[idx]){
			while(s<e && h[idx]>h[d[e-1]])	--e;
			d[e++]=idx--;
		}
		if(l[i]<h[d[s]])	l[i]=h[d[s]];
	}
	if(l[0]<h[0])	l[0]=h[0];
	for(int i=0;i<N;++i)	printf("%d ", l[i]);
	return 0;
}
