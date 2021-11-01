#include<iostream>
#include<cstring>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char L[11], R[11];
	cin>>L>>R;
	int N=strlen(L);
	if(N!=strlen(R)){
		cout<<"0\n";
		return 0;
	}
	int ans=0;
	for(int i=0;i<N;++i){
		if(L[i]==R[i]){
			if(L[i]=='8'){
				ans++;
			}
		}else{
			break;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
