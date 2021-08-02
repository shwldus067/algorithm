#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, ans=4;
	cin>>n;
	for(int a=1;a<224;++a){
		int A=a*a;
		if(A==n)	ans=1;
		for(int b=1;b<=a;++b){
			int B=A+b*b;
			if(B==n)	ans=ans>2 ? 2:ans;
			for(int c=1;c<=b;++c){
				if(B+c*c==n)	ans=ans>3 ? 3:ans;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
