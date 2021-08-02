#include<iostream>
using namespace std;
int d1, d2, v[2000], idx;
bool chk[2001];
int gcd(int a, int b){
	int c;
	while(b){
		c=a;
		a=b;
		b=c%b;
	}
	return a;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>d1>>d2;
	int ans=1;
	for(int i=d1;i<=d2;++i){
		idx=0;
		for(int j=1;j<i;++j){
			int g=gcd(j, i);
			g=i/g;
			if(!chk[g]){
				ans++;
				v[idx++]=g;
			}
		}
		for(int i=0;i<idx;++i)	chk[v[i]]=true;
	}
	cout<<ans<<"\n";
	return 0;
}
