#include<iostream>
using namespace std;
int T, N;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		int f=0;
		for(int i=5;i<=N;i*=5){
			f+=N/i;
		}
		cout<<f<<"\n";
	}
	return 0;
}
