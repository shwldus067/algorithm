#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, cnt[10]={0, };
	cin>>N;
	for(int i=1;i<10;++i){
		for(int j=1;j<=N;j*=10){
			int t=(N/j)%10;
			if(t>i){
				cnt[i]+=j+N/(10*j)*j;
			}else if(t==i){
				cnt[i]+=N/(10*j)*j+N%j+1;
			}else{
				cnt[i]+=N/(10*j)*j;
			}
		}
	}
	cnt[0]=N/10;
	for(int j=10;j*10<=N;j*=10){
		int t=N/j;
		if(t%10==0)	cnt[0]+=(t/10-1)*j+N%j+1;
		else	cnt[0]+=t/10*j;
	}
	for(int i=0;i<10;++i)	cout<<cnt[i]<<" ";
	return 0;
}
