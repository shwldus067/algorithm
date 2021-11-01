#include<iostream>
#include<cstring>
using namespace std;
#define mod 10007
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, H, arr[50][1001]={0, }, len;
	char str[50];
	cin>>N>>M>>H;
	cin.getline(str, 50);
	for(int i=0;i<N;++i){
		cin.getline(str, 50);
		len=strlen(str);
		for(int l=0;l<len;){
			while(str[l]==' ')	++l;
			int t=0;
			while(str[l]!=' ' && l<len){
				t*=10;
				t+=str[l]-'0';
				++l;
			}
			for(int k=H;k>t;--k){
				for(int j=i-1;j>=0;--j){
					if(arr[j][k-t])	arr[i][k]=(arr[i][k]+arr[j][k-t])%mod;
				}
			}
			arr[i][t]=(arr[i][t]+1)%mod;
		}
	}
	int ans=0;
	for(int i=0;i<N;++i)	ans=(ans+arr[i][H])%mod;
	cout<<ans<<"\n";
	return 0;
}
