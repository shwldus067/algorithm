#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int d[11][10]={0, }, N, sum=0, f=0, i;
	cin>>N;
	if(N<=10){
		cout<<N-1<<"\n";
		return 0;
	}
	for(int i=0;i<10;++i)	d[1][i]=1;
	N-=10;
	for(i=2;i<11;++i){	//길이 
		for(int j=1;j<10;++j){	//시작 
			for(int k=0;k<j;++k)	//두번째 
				d[i][j]+=d[i-1][k];
			sum+=d[i][j];
		}
		if(sum>=N){
			f=1;break;
		}
		N-=sum;
		sum=0;
	}
	if(f){
		for(;i>0;--i){
			for(int j=0;j<10;++j){
				if(d[i][j]>=N){
					cout<<j;
					break;
				}else	N-=d[i][j];
			}
		}
	}else{
		cout<<"-1\n";
	}
	return 0;
}
