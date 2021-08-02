#include<iostream>
#include<cmath>
#include<vector>
#define PI 3.14159265
using namespace std;
typedef long long ll;
struct wing{
	double x, y, d;
}w[300000];
int N;
vector<int> V;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	double r, R=0;
	for(int i=0;i<N;++i){
		cin>>w[i].x>>w[i].y;
		r=w[i].x*w[i].x+w[i].y*w[i].y;
		if(r>R)	V.clear(), V.push_back(i), R=r;
		else if(r==R)	V.push_back(i);
	}
	double ans=0, tmp1, tmp2, tmp, fir;
	fir=tmp1=atan2(w[V[0]].y, w[V[0]].x);
	for(int i=1;i<V.size();++i){
		tmp2=atan2(w[V[i]].y, w[V[i]].x);
		tmp=tmp2-tmp1+(tmp2<=tmp1 ? 2.0*PI:0);
		tmp1=tmp2;
		if(ans<tmp)	ans=tmp;
	}
	tmp=fir-tmp1+(fir<=tmp1 ? 2.0*PI:0);
	if(ans<tmp)	ans=tmp;
	cout.precision(14);
	cout<<ans*180.0/PI<<"\n";
	return 0;
}
