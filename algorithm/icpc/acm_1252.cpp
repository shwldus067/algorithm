#include<iostream>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char N[81], M[81], ans[82]={0, };
	cin>>N>>M;
	int n=strlen(N), m=strlen(M), p=0;
	for(int i=n-1, j=m-1, k=0;i!=n || j!=m;++k){
		if(N[i]=='1'){
			if(M[j]=='1'){
				if(p)	ans[k]='1', p=1;
				else	ans[k]='0', p=1;
			}
			else{
				if(p)	ans[k]='0', p=1;
				else	ans[k]='1', p=0;
			}
		}else{
			if(M[j]=='1'){
				if(p)	ans[k]='0', p=1;
				else	ans[k]='1', p=0;
			}else{
				if(p)	ans[k]='1', p=0;
				else	ans[k]='0', p=0;
			}
		}
		if(i>0 && i!=n)	i--;
		else	i=n;
		if(j>0 && j!=m)	j--;
		else	j=m;
	}
	if(p)	ans[strlen(ans)]='1';
	int f=1;
	for(int i=strlen(ans)-1;i>=0;--i){
		if(f && ans[i]=='0')	continue;
		f=0;
		cout<<ans[i];
	}
	if(f)	cout<<"0\n";
	return 0;
}
