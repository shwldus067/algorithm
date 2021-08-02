#include<cstdio>
#include<stack>
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
	int N, t=1, a;
	long long ans=0;
	N=readInt();
	stack<pair<int, int> > S;
	while(N--){
		a=readInt();
		while(S.size() && S.top().first<a)	ans+=S.top().second, S.pop();
		if(S.empty())	S.push({a, 1});
		else{
			if(S.top().first==a){
				ans+=S.top().second;
				int cnt=S.top().second;
				S.pop();
				if(S.size())	++ans;
				S.push({a, cnt+1});
			}
			else	++ans, S.push({a, 1});
		}
	}
	printf("%lld\n", ans);
	return 0;
}
