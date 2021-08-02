#include<stdio.h>
#include<algorithm>
using namespace std;
typedef pair<int, int> pii;
char buf[1<<20];
inline char read(){
	static int idx=1<<20;
	if(idx==1<<20){
		fread(buf, 1, 1<<20, stdin);
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
pii dq[5000000];
int main(){
	int N, L, s=0, e=0, A;
	N=readInt();L=readInt();
	--L;
	for(int i=0;i<N;++i){
		A=readInt();
		while(s<e && dq[s].second<i-L)	++s;
		while(s<e && dq[e-1].first>=A)	--e;
		dq[e++]={A, i};
		printf("%d ", dq[s].first);
	}
	return 0;
}
