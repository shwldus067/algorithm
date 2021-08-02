#include<iostream>
using namespace std;
long long pow(long long a, int b, int c){
	long long res=1;
	while(b){
		if(b%2){
			res=(long long)(res*a)%(long long)c;
		}
		a=(a*a)%(long long)c;
		b>>=1;
	}
	return res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long a;
	int b, c;
	cin>>a>>b>>c;
	cout<<pow(a, b, c)<<"\n";
	return 0;
}
