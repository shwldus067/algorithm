#include<iostream>
using namespace std;
char w[4][9];
int p[4]={1000, 1000, 1000, 1000};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<4;++i)	cin>>w[i];
	int K, i;
	cin>>K;
	while(K--){
		int a, b;
		cin>>a>>b;
		--a;
		for(i=a;i<3 && w[i][(p[i]+2)%8]!=w[i+1][(p[i+1]-2)%8];++i);
		for(;i>a;--i){
			if((i-a)&1)	p[i]+=b;
			else	p[i]-=b;
		}
		for(i=a;i>0 && w[i][(p[i]-2)%8]!=w[i-1][(p[i-1]+2)%8];--i);
		for(;i<=a;++i){
			if((a-i)&1)	p[i]+=b;
			else	p[i]-=b;
		}
	}
	cout<<(w[0][p[0]%8]-'0')+(w[1][p[1]%8]-'0')*2+(w[2][p[2]%8]-'0')*4+(w[3][p[3]%8]-'0')*8<<"\n";
	return 0;
}
