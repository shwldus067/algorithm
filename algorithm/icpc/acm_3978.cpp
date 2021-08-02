#include<iostream>
using namespace std;
const int MAX=260000;
int T, N, M, K;
char str[10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N>>M>>K>>str;
		bool flag=false;
		int mod=K;
		if(K==1){
			for(int i=0;i<M;++i)	cout<<'a';
			cout<<"\n";
			continue;
		}
		for(int l=1;!flag;++l){
			int H=0;
			bool chk[MAX]={false, };
			for(int i=0;i<l-1;++i)	H=(H*K+str[i]-'a')%mod;
			for(int i=l-1;i<N;++i){
				H=(H*K+str[i]-'a')%mod;
				chk[H]=true;
			}
			for(int i=0;i<mod;++i){
				if(!chk[i]){
					char res[l+1];
					H=i;
					for(int j=0;j<l;++j){
						res[l-j-1]=H%K+'a';
						H/=K;
					}
					res[l]=0;
					cout<<res<<"\n";
					flag=true;
					break;
				}
			}
			mod*=K;
		}
	}
	return 0;
}
