#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
struct point{
	ll x, y, q;
	point operator-(const point &p){
		return {x-p.x, y-p.y};
	}
	bool operator<(const point &p)const{
		return y*p.x<x*p.y;
	}
	bool operator==(const point &p){
		return x*p.y==y*p.x;
	}
	void rotate(){
		q=(q==3 ? 0:q+1);
		swap(x, y);
		y=-y;
	}
}P[1500], Q[1500];
int main(){
	int N, ans=0, cnt[4];
	scanf("%d", &N);
	for(int i=0;i<N;++i)	scanf("%lld %lld", &P[i].x, &P[i].y);
	for(int i=0;i<N;++i){
		int f=0;
		for(int j=0;j<N;++j){
			if(i==j)	f=-1;
			else	Q[j+f]=P[j]-P[i];
		}
		for(int j=0;j<N-1;++j){
			while(Q[j].x<=0 || Q[j].y<0)	Q[j].rotate();
		}
		sort(Q, Q+N-1);
		for(int j=0, k;j<N-1;j=k){
			cnt[0]=cnt[1]=cnt[2]=cnt[3]=0;
			for(k=j;(k<N-1) && (Q[j]==Q[k]);++k)	cnt[Q[k].q]++;
			ans+=cnt[0]*cnt[1]+cnt[1]*cnt[2]+cnt[2]*cnt[3]+cnt[3]*cnt[0];
		}
	}
	printf("%d\n", ans);
	return 0;
}
