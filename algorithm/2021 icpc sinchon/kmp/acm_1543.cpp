#include<iostream>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char a[2501], b[51];
	cin.getline(a, 2501);
	cin.getline(b, 51);
	int as=strlen(a), bs=strlen(b), f[50]={0, }, ans=0;
	for(int i=1, j=0;i<bs;++i){
		while(j && b[j]!=b[i])	j=f[j-1];
		if(b[j]==b[i])	f[i]=++j;
	}
	for(int i=0, j=0;i<as;++i){
		while(j && a[i]!=b[j])	j=f[j-1];
		if(a[i]==b[j])	++j;
		if(j==bs){
			ans++;
			j=0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
