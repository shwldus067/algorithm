#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	long long a=1e18, b=-1e18, c=1e18, d=-1e18, x, y;
	unsigned long long ans;
	cin>>N;
	while(N--){
		cin>>x>>y;
		a=min(a, x+y);b=max(b, x+y);
		c=min(c, y-x);d=max(d, y-x);
	}
	if(b-a<d-c)	ans=d-c;
	else	ans=b-a;
	if(ans&1)	cout<<ans*ans/2<<".5\n";
	else cout<<ans*ans/2<<"\n";
	return 0;
}
