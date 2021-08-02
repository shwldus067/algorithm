#include<cstdio>
#include<algorithm>
#include<queue>
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
int main(){
	int N, D, a, b, ans=0;
	pii arr[100000];
	N=readInt();
	for(int i=0;i<N;++i){
		a=readInt();b=readInt();
		if(a<b)	arr[i]={a, b};
		else	arr[i]={b, a};
	}
	D=readInt();
	sort(arr, arr+N, greater<pii>());
	priority_queue<int> pq;
	for(int i=0;i<N;++i){
		pq.push(arr[i].second);
		while(pq.size() && arr[i].first+D<pq.top())	pq.pop();
		if(ans<pq.size())	ans=pq.size();
	}
	printf("%d\n", ans);
	return 0;
}
