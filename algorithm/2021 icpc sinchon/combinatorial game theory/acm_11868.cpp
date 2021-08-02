#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, P=0, t;
	cin>>N;
	for(int i=0;i<N;++i)	cin>>t, P^=t;
	if(P)	cout<<"koosaga\n";
	else	cout<<"cubelover\n";
	return 0;
}
