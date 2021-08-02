#include<iostream>
using namespace std;
typedef long long ll;
ll N, A;
ll inverse(ll a, ll b){
	ll r, t, x=0, y=1;
	while(a!=1){
		if(b==0)	return -1;
		r=a%b;
		t=x-y*(a/b);
		a=b;
		b=r;
		x=y;
		y=t;
	}
	if(x<0)	x=x+N;
	return x;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>A;
	cout<<N-A<<" ";
	cout<<inverse(N, A)<<"\n";
	return 0;
}
