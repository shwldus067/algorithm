#include<iostream>
#include<cstring>
using namespace std;
char S[1000001], P[1000001];
int f[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>S>>P;
	int n=strlen(S), m=strlen(P);
	for(int i=1, j=0;i<m;++i){
		while(j>0 && P[i]!=P[j])	j=f[j-1];
		if(P[i]==P[j])	f[i]=++j;
	}
	for(int i=0, j=0;i<n;++i){
		while(j>0 && S[i]!=P[j])	j=f[j-1];
		if(S[i]==P[j]){
			if(j==m-1){
				cout<<"1\n";
				return 0;
			}
			++j;
		}
	}
	cout<<"0\n";
	return 0;
}
