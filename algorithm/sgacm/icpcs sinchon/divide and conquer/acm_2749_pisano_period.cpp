#include<iostream>
using namespace std;
const int mod=1000000;
const int p=mod/10*15;
long long n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	n%=p;
	int a=0, b=1, c;
	while(n--){
		c=a+b;
		if(c>=mod)	c-=mod;
		a=b, b=c;
	}
	cout<<a<<"\n";
	return 0;
}
