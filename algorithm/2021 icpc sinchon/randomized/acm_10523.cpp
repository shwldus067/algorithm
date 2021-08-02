#include<iostream>
#include<random>
#include<chrono>
#include<vector>
using namespace std;
int N, P;
pair<int, int> p[100000];
int sol(int x, int y){
	int dx=p[x].first-p[y].first, dy=p[x].second-p[y].second;
	int ret=0;
	for(int i=0;i<N;++i){
		int xx=p[i].first-p[x].first, yy=p[i].second-p[x].second;
		if(1ll*dx*yy-1ll*dy*xx==0)	++ret;
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>P;
	for(int i=0;i<N;++i)	cin>>p[i].first>>p[i].second;
	if(N==1){
		cout<<"possible\n";
		return 0;
	}
	mt19937 rd = mt19937((unsigned)chrono::steady_clock::now().time_since_epoch().count());
	uniform_int_distribution<int> ran(0, N-1);
	for(int i=0;i<100;++i){
		int x=ran(rd), y=ran(rd);
		while(x==y)	y=ran(rd);
		if(sol(x, y)*100>=N*P){
			cout<<"possible\n";
			return 0;
		}
	}
	cout<<"impossible\n";
	return 0;
}
