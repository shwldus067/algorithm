#include<iostream>
#include<algorithm>
using namespace std;
int N, inn[50][9], ans, arr[8]={1, 2, 3, 4, 5, 6, 7, 8};
void sol(){
	int res=0, ord[9], bat=0;
	bool run[3]={0, };
	for(int i=0;i<3;++i){
		ord[i]=arr[i];
	}
	ord[3]=0;
	for(int i=4;i<9;++i){
		ord[i]=arr[i-1];
	}
	for(int n=0;n<N;++n){
		int out=0;
		run[0]=run[1]=run[2]=0;
		while(out<3){
			switch(inn[n][ord[bat]]){
				case 0: out++;break;
				case 1:
					if(run[2])	res++;
					run[2]=run[1];run[1]=run[0];run[0]=1;
					break;
				case 2:
					if(run[1])	res++;
					if(run[2])	res++;
					run[2]=run[0];run[0]=0;run[1]=1;
					break;
				case 3:
					if(run[0])	res++;
					if(run[1])	res++;
					if(run[2])	res++;
					run[1]=run[0]=0;run[2]=1;
					break;
				case 4:
					if(run[0])	res++;
					if(run[1])	res++;
					if(run[2])	res++;
					res++;
					run[0]=run[1]=run[2]=0;
					break;
			}
			bat=bat<8 ? bat+1:0;
		}
	}
	if(res>ans)	ans=res;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<9;++j){
			cin>>inn[i][j];
		}
	}
	do{
		sol();
	}while(next_permutation(arr, arr+8));
	cout<<ans<<"\n";
	return 0;
}
