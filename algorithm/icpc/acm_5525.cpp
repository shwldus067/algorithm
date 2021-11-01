#include<iostream>
using namespace std;
int main(){
	int N, M, L, cnt=0, ans=0;
	char S[1000001], C=0;
	cin>>N>>M>>S;
	L=N+N;
	for(int i=0;i<M;++i){
		if(S[i]=='I'){
			if(C=='O'){
				if(cnt==L)	cnt--, ans++;
				else	cnt++;
			}else{
				cnt=1;
			}
			C='I';
		}else{
			if(C=='I')	cnt++;
			else	cnt=0;
			C='O';
		}
	}
	cout<<ans<<"\n";
	return 0;
}
