#include<iostream>
using namespace std;
int d1, d2;
bool chk[2001][2001];
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
		for(int j=1;j<i;++j){
			int g=gcd(j, i);
			int a=j/g, b=i/g;
			if(!chk[a][b]){
				chk[a][b]=true;
				ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
