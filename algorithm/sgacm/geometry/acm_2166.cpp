#include<iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int N;
pll arr[10000];
ll ccw(pll a, pll b, pll c){
	b={b.first-a.first, b.second-a.second};
	c={c.first-a.first, c.second-a.second};
	ll ret=b.first*c.second-b.second*c.first;
	return ret;
}
int main(){
	scanf("%d", &N);
	for(int i=0;i<N;i++)	cin>>arr[i].first>>arr[i].second;
	pll f=arr[0];
	ll area=0;
	for(int i=1;i<N-1;i++){
		area+=ccw(f, arr[i], arr[i+1]);
	}
	if(area<0)	area=-area;
	printf("%lld.", area/2);
	if(area%2)	printf("5\n");
	else 	printf("0\n");
	return 0;
}
