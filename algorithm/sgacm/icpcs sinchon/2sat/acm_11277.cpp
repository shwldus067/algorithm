#include<iostream>
using namespace std;
int N, M, a[100], b[100];
int f(int a, int b){
	return a<0 ? 1-(b>>-a-1)%2:(b>>a-1)%2;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	for(int i=0;i<M;++i){
		cin>>a[i]>>b[i];
	}
	bool res=false;
	for(int i=0;i<1<<N;++i){
		res=true;
		for(int j=0;j<M;++j){
			res&=f(a[j], i)|f(b[j], i);
			if(!res)	break;
		}
		if(res)	break;
	}
	cout<<res<<"\n";
	return 0;
}
