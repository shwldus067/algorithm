#include<iostream>
using namespace std;
int N, inn[50][10], ans, ord[10], buf[30];
void sol(int k){
	if(k>9){
		int res=0, bat=1;
		for(int i=0;i<N;++i){
			int out=0, idx=0;
			for(int j=bat;out<3;j=bat){
				if(inn[i][ord[j]]){
					buf[++idx]=inn[i][ord[j]];
				}
				else	out++;
				bat=bat<9 ? bat+1:1;
			}
			int tmp=0;
			while(idx){
				tmp+=buf[idx];
				if(tmp>3){
					res+=idx;
					break;
				}
				idx--;
			}
		}
		if(ans<res)	ans=res;
		return;
	}
	for(int i=1;i<4;++i){
		if(!ord[i]){
			ord[i]=k;
			sol(k+1);
			ord[i]=0;
		}
	}
	for(int i=5;i<10;++i){
		if(!ord[i]){
			ord[i]=k;
			sol(k+1);
			ord[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=1;j<10;++j){
			cin>>inn[i][j];
		}
	}
	ord[4]=1;
	sol(2);
	cout<<ans<<"\n";
	return 0;
}
