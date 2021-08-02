#include<iostream>
using namespace std;
int mind[22]={0, 0, 1, 7, 4, 2, 6, 8, 10, 18, 22, 20, 28, 68, 88, 108,
			 188, 200, 208, 288, 688, 888};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int tc, n, k;
	cin>>tc;
	while(tc--){
		cin>>n;
		if(n<22)	cout<<mind[n];
		else{
			k=(n-1)/7;
			if(!(n%7))	for(int i=0;i<=k;++i)	cout<<"8";
			else{
				cout<<mind[n-(k-2)*7];
				for(int i=2;i<k;++i)	cout<<"8";
			}
		}
		cout<<" ";
		if(n&1)	cout<<"7";
		else	cout<<"1";
		for(int i=3;i<n;i+=2)	cout<<"1";
		cout<<"\n";
	}
	return 0;
}
