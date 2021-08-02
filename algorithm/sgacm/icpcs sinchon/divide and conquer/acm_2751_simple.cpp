#include<iostream>
using namespace std;
int N;
bool p[1000001], m[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t;
	for(int i=0;i<N;++i){
		cin>>t;
		if(t<0){
			m[-t]=true;
		}
		else{
			p[t]=true;
		}
	}
	for(int i=1000000;i>0;--i){
		if(m[i])	cout<<-i<<"\n";
	}
	for(int i=0;i<=1000000;++i){
		if(p[i])	cout<<i<<"\n";
	}
	return 0;
}
