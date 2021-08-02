#include<iostream>
using namespace std;
int N, M;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int a, b, smin=1000, pmin=1000, pay=0;
	for(int i=0;i<M;++i){
		cin>>a>>b;
		if(a<smin)	smin=a;
		if(b<pmin)	pmin=b;
	}
	if(smin>=pmin*6){
		pay=pmin*N;
		cout<<pay<<"\n";
		return 0;
	}
	b=smin*(N/6+1);
	pay=smin*(N/6)+pmin*(N%6);
	if(pay>b)	pay=b;
	cout<<pay<<"\n";
	return 0;
}
