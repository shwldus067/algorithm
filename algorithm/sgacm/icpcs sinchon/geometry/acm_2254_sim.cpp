#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int N, x, y;
typedef pair<int, int> pii;
pii p[1001], ch[1001], tmp[1001];
int ccw(pii a, pii b, pii c){
	int x1=b.first-a.first, x2=c.first-a.first;
	int y1=b.second-a.second, y2=c.second-a.second;
	ll ret=1ll*x1*y2-1ll*x2*y1;
	if(ret>0)	return 1;
	else if(ret==0)	return 0;
	else return -1;
}
bool cmp(pii &a, pii &b){
	int ret=ccw(p[0], a, b);
	return ret>0 || (ret==0 && a<b);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>x>>y;
	for(int i=0;i<N;++i){
		int a, b;
		cin>>a>>b;
		p[i]={a, b};
	}
	p[N]={x, y};
	++N;
	int ans=0;
	while(1){
		swap(p[0], *min_element(p, p+N));
		sort(p+1, p+N, cmp);
		int top=0, cnt=0;
		bool flag=1;
		for(int i=0;i<N;++i){
			while(top>1 && ccw(ch[top-2], ch[top-1], p[i])<=0){
				tmp[cnt++]=ch[--top];
				if(ch[top].first==x && ch[top].second==y)	flag=0;
			}
			ch[top++]=p[i];
		}
		if(flag)	break;
		for(int i=0;i<cnt;++i){
			p[i]=tmp[i];
		}
		N=cnt;
		++ans;
	}
	cout<<ans<<"\n";
	return 0;
}
