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
bool a[360000], b[720000];
int f[360000];
int main(){
	int N, t;
	N=readInt();
	for(int i=0;i<N;++i){
		t=readInt();
		a[t]=1;
	}
	for(int i=0;i<N;++i){
		t=readInt();
		b[t]=1;b[t+360000]=1;
	}
	for(int i=1, j=0;i<360000;++i){
		while(j && a[i]!=a[j])	--j;
		if(a[i]==a[j])	f[i]=++j;
	}
	for(int i=0, j=0;i<720000;++i){
		while(j && a[j]!=b[i])	j=f[j-1];
		if(a[j]==b[i]){
			if(++j==360000){
				printf("possible\n");
				return 0;
			}
		}
	}
	printf("impossible\n");
	return 0;
}
