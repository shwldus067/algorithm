#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int N, x[60], y[60];
char inp[8];
struct Rec{
	int x, y, xx, yy;
}rec[30];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int crd[4];
		for(int j=0;j<4;++j){
			cin>>inp;
			int tmp=0, dot=1;
			for(int k=0;k<strlen(inp);++k){
				if(inp[k]=='.'){
					dot=0;
					continue;
				}
				tmp=tmp*10+(int)(inp[k]-'0');
			}
			if(dot){
				tmp*=10;
			}
			crd[j]=tmp;
		}
		crd[2]+=crd[0], crd[3]+=crd[1];
		rec[i]={crd[0], crd[1], crd[2], crd[3]};
		x[i]=crd[0], x[i+N]=crd[2];
		y[i]=crd[1], y[i+N]=crd[3];
	}
	int M=2*N, ans=0;
	sort(x, x+M);
	sort(y, y+M);
	for(int i=1;i<M;++i){
		for(int j=1;j<M;++j){
			for(int k=0;k<N;++k){
				if(rec[k].x<=x[i-1] && rec[k].xx>=x[i] && rec[k].y<=y[j-1] && rec[k].yy>=y[j]){
					ans+=(x[i]-x[i-1])*(y[j]-y[j-1]);
					break;
				}
			}
		}
	}
	if(ans%100==0){
		cout<<ans/100<<"\n";
	}
	else{
		cout<<ans/100<<"."<<ans%100<<"\n";
	}
	return 0;
}
