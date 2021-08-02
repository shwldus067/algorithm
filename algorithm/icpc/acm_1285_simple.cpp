#include<iostream>
using namespace std;
int N, arr[20], res=0;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	char t;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin>>t;
			if(t=='T'){
				res++;
				arr[i]|=(1<<j);
			}
		}
	}
	for(int i=0;i<=(1<<N)-1;i++){
		int cnt=0;
		for(int j=0;j<N;j++){
			int pc=__builtin_popcount(arr[j]^i);
			cnt+=min(N-pc, pc);
			if(cnt>=res)	break;
		}
		res=min(res, cnt);
	}
	cout<<res<<"\n";
	return 0;
}
