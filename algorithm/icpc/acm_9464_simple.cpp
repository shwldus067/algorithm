#include<iostream>
#include<algorithm>
using namespace std;
int T, L, V[2100], vi;
int gcd(int a, int b){
	int c;
	while(b){
		c=b;
		b=a%b;
		a=c;
	}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x, y;
	for(x=2;x<=100;x++){
		for(y=x-1;y>=1;y-=2){
			if(gcd(x, y)==1){
				int a=2*x*y, b=x*x-y*y;
				if(gcd(a, b)==1){
					V[vi++]=2*(a+b);
				}
			}
		}
	}
	sort(V, V+vi);
	cin>>T;
	while(T--){
		cin>>L;
		int ans=0;
		for(int i=0;i<vi;++i){
			int tmp=V[i];
			if(L>=tmp){
				L-=tmp;
				ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
