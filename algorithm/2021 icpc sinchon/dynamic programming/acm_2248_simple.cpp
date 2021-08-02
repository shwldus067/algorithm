#include<iostream>
using namespace std;
int d[32][32];
char ans[32];
int N, L, idx=0;
long long I;
int sol(int a, int b){
	if(a==0 || b<0)	return b>=0;
	if(d[a][b])	return d[a][b];
	return d[a][b]=sol(a-1, b)+sol(a-1, b-1);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>L>>I;
	int tmp=0;
	while(N){
		if((tmp=sol(N-1, L))<I){
			ans[idx++]='1';
			I-=tmp;
			L--;
		}
		else	ans[idx++]='0';
		N--;
	}
	cout<<ans<<"\n";
	return 0;
}
