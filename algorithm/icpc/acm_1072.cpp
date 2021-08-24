#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long X, Y, Z;
	cin>>X>>Y;
	Z=Y*100/X;
	if(X==Y || Z==99){
		cout<<"-1\n";
		return 0;
	}
	long long l=0, r=X;
	while(l<r){
		long long m=(l+r)/2;
		long long t=(Y+m)*100/(X+m);
		if(t>Z)	r=m;
		else	l=m+1;
	}
	cout<<l<<"\n";
	return 0;
}
