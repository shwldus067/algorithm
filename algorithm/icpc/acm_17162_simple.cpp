#include<iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int arr[200000]={0, };
	int s=0, e=0, cnt=0, mod[100]={0, };
	int Q, M, a;
	cin>>Q>>M;
	while(Q--){
		cin>>a;
		if(a==1){
			cin>>arr[e];
			arr[e]%=M;
			if(!mod[arr[e++]]++)	++cnt;
			while(cnt==M && s<e && mod[arr[s]]>1)	--mod[arr[s++]];
		}else if(a==2){
			if(e==0)	continue;
			if(!--mod[arr[--e]])	--cnt;
			while(cnt!=M && s>0)	cnt+=!mod[arr[--s]]++;
		}else{
			cout<<(cnt==M?e-s:-1)<<"\n";
		}
	}
	return 0;
}
