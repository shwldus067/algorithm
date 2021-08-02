#include<iostream>
using namespace std;
int N;
char ans[1100000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int s=1;
	while(s<N)	s*=2;
	for(int i=0;i<s;++i){
		ans[i]='#';
	}
	int d=s-N;
	int x=s/2;
	int p=s/2;
	while(p>=2){
		if(p/2<=d){
			d-=p/2;
			for(int i=x+p/2;i<x+p;++i){
				ans[i]='.';
			}
			x-=p/2;
		}
		else{
			x+=p/2;
		}
		p/=2;
	}
	cout<<ans<<"\n";
	return 0;
}
