#include<iostream>
using namespace std;
int N;
int B[50];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N;
	int i, res=0;
	for(i=0;i<N;i++)	cin>>B[i];
	while(1){
		bool flag2=true, flag0=true;
		for(i=0;i<N;i++){
			if(B[i])	flag0=false;
			if(B[i]&1){
				res++;
				flag2=false;
				B[i]--;
			}
		}
		if(flag0)	break;
		if(flag2){
			for(i=0;i<N;i++){
				B[i]/=2;
			}
			res++;
		}
	}
	cout<<res<<"\n";
	return 0;
}
