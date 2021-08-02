#include<iostream>
using namespace std;
int A, B, C;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>A>>B>>C;
	cout<<(A+B)%C<<"\n";
	cout<<((A%C)+(B%C))%C<<"\n";
	cout<<(A*B)%C<<"\n";
	cout<<((A%C)*(B%C))%C<<"\n";
	return 0;
}
