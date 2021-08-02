#include<iostream>
using namespace std;
int t, dh, ds, hd, hs, sd, sh;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>dh>>ds>>hd>>hs>>sd>>sh;
		if(hd>hs || sd>sh || hs*sh-sh*hd-sd*hs<0){
			cout<<"GOD\n";
		}else{
			cout<<"KDH\n";
		}
	}
}
