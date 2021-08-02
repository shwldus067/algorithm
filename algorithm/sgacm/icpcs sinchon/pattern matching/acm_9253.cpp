#include<iostream>
#include<cstring>
using namespace std;
char A[2][200001], B[200001];
int f[200000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>A[0]>>A[1]>>B;
	int alen[2]={strlen(A[0]), strlen(A[1])};
	int blen=strlen(B);
	for(int i=1, j=0;i<blen;++i){
		while(j>0 && B[i]!=B[j])	j=f[j-1];
		if(B[i]==B[j])	f[i]=++j;
	}
	bool res=true;
	for(int k=0;k<2;++k){
		bool chk=false;
		for(int i=0, j=0;i<alen[k];++i){
			while(j>0 && A[k][i]!=B[j])	j=f[j-1];
			if(A[k][i]==B[j]){
				if(j==blen-1){
					chk=true;
					break;
				}
				++j;
			}
		}
		if(!chk)	res=false;
	}
	if(res)	cout<<"YES\n";
	else	cout<<"NO\n";
	return 0;
}
