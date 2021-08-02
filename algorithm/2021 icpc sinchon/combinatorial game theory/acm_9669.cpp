#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long N;
	cin>>N;
	N%=7;
	if(N==0 || N==2)	cout<<"CY\n";
	else	cout<<"SK\n";
	return 0;
}
