#include<iostream>
using namespace std;
int n;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	int m=n%8;
	if(m==0)	cout<<"2\n";
	else if(m<=5)	cout<<m<<"\n";
	else	cout<<10-m<<"\n";
	return 0;
}
