#include<iostream>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char str[5001];
	cin>>str;
	int f[5001], N=strlen(str), ans=0;
	for(int k=0;k<N;++k){
		f[k]=k;
		for(int i=k+1, j=k;i<N;++i){
			while(j>k && str[i]!=str[j])	j=f[j-1];
			if(str[i]==str[j])	f[i]=++j;
			else f[i]=k;
			ans=max(ans, f[i]-k);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
