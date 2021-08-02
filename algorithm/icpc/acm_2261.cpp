#include<iostream>
#include<set>
#include<cmath>
#include<algorithm>
using namespace std;
typedef pair<int, int> P;
#define x first
#define y second
P point[100000];
struct cmp{
	bool operator()(P a, P b)const{
		if(a.y==b.y)	return a.x<b.x;
		return a.y<b.y;
	}
};
set<P, cmp> S;
int dist(P a, P b){
	int dx=a.x-b.x, dy=a.y-b.y;
	return dx*dx+dy*dy;
}
bool cmp(P &a, P &b){
	return a.x<b.x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>point[i].x>>point[i].y;
	}
	sort(point, point+N, cmp);
	int ans=dist(point[0], point[1]);
	S.insert(point[0]);
	S.insert(point[1]);
	int pos=0;
	for(int i=2;i<N;++i){
		while(pos<i){
			int dx=point[pos].x-point[i].x;
			if(dx*dx>ans){
				S.erase(point[pos]);
				++pos;
			}
			else	break;
		}
		int dis=(int)sqrt((double)ans)+1;
		set<P>::iterator l=S.lower_bound({-10001, point[i].y-dis});
		set<P>::iterator r=S.lower_bound({10001, point[i].y+dis});
		for(set<P>::iterator it=l;it!=r;it++){
			ans=min(ans, dist(*it, point[i]));
		}
		S.insert(point[i]);
	}
	cout<<ans<<"\n";
	return 0;
}
