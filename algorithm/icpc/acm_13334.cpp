#include<cstdio>
#include<algorithm>
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
typedef pair<int, int> pii;
bool chk[100000], in[100000];
int main(){
	int N, D, a, b, M, cnt=0, s, e, t, ans=0;
	int ds=0, de=0;
	pii arr[200000];
	N=readInt();
	M=N+N;
	for(int i=0;i<N;++i){
		a=readInt();b=readInt();
		if(a>b)	swap(a, b);
		arr[i]={a, i};
		arr[i+N]={b, i+N};
	}
	D=readInt();
	sort(arr, arr+M);
	for(int i=0;i<M;++i){
		if(arr[i].second>=N)	continue;
		s=arr[i].first, e=s+D;
		while(ds<de && arr[ds].first<s){
			t=arr[ds].second;
			if(t<N){
				if(in[t])	cnt--;
				chk[t]=in[t]=0;
			}
			++ds;
		}
		while(de<M && arr[de].first<=e){
			if((t=arr[de].second)<N){
				chk[t]=1;
			}else{
				t-=N;
				if(chk[t])	++cnt, in[t]=1;
			}
			++de;
		}
		if(ans<cnt)	ans=cnt;
	}
	printf("%d\n", ans);
	return 0;
}
