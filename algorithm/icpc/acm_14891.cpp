#include<iostream>
using namespace std;
char w[4][9];
void rot(int idx, int r, int d){
	if(d!=-1 && idx<3 && w[idx][2]!=w[idx+1][6])
		rot(idx+1, -r, 1);
	if(d!=1 && idx && w[idx][6]!=w[idx-1][2])
		rot(idx-1, -r, -1);
	int t;
	if(r==1){
		t=w[idx][7];
		for(int i=7;i>0;--i){
			w[idx][i]=w[idx][i-1];
		}
		w[idx][0]=t;
	}
	else{
		t=w[idx][0];
		for(int i=0;i<7;++i){
			w[idx][i]=w[idx][i+1];
		}
		w[idx][7]=t;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i=0;i<4;++i)	cin>>w[i];
	int K;
	cin>>K;
	while(K--){
		int a, b;
		cin>>a>>b;
		rot(a-1, b, 0);
	}
	cout<<(w[0][0]-'0')+(w[1][0]-'0')*2+(w[2][0]-'0')*4+(w[3][0]-'0')*8<<"\n";
	return 0;
}
