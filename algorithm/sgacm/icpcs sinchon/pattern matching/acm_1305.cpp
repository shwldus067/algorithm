#include<iostream>
#include<cstring>
using namespace std;
char P[1000001];
int f[1000001], L;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>L>>P;
	for(int i=1, j=0;i<L;++i){
		while(j>0 && P[i]!=P[j])	j=f[j-1];
		if(P[i]==P[j])	f[i]=++j;
	}
	cout<<L-f[L-1]<<"\n";
	return 0;
}
