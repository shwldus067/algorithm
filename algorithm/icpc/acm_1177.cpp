#include<iostream>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
int N, R, X, Y, VX, VY, A, idx;
pair<double, double> p[50000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>R>>X>>Y>>VX>>VY;
	for(int i=0;i<N;++i){
		int x, y, vx, vy;
		cin>>x>>y>>vx>>vy;
		int dvx=vx-VX, dvy=vy-VY, dx=x-X, dy=y-Y;
		int a=dvx*dvx+dvy*dvy;
		int b=2*(dvx*dx+dvy*dy);
		int c=dx*dx+dy*dy-R*R;
		if(a==0){
			if(b==0)	A+=(c<=0);
			else if(1ll*b*c<=0)	p[idx++]={0.0, -1.0*c/b};
		}
		else{
			long long D=1ll*b*b-4ll*a*c;
			if(D>=0){
				double t1=(-b-sqrt(D))/2/a, t2=(-b+sqrt(D))/2/a;
				if(t2>=0)	p[idx++]={max(0.0, t1), t2};
			}
		}
	}
	sort(p, p+idx);
	int res=0;
	priority_queue<double, vector<double>, greater<double> > PQ;
	for(int i=0;i<idx;++i){
		PQ.push(p[i].second);
		while(PQ.size() && PQ.top()<p[i].first) PQ.pop();
		res=max(res, (int)PQ.size());
	}
	cout<<res+A<<"\n";
	return 0;
}
