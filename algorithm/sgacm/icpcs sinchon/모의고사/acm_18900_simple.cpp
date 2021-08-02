#include<iostream>
using namespace std;
int N, arr[1000001], ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		int t;
		cin>>t;
		arr[t]=i;
	}
	if(N==1){
		cout<<"1\n";
		return 0;
	}
	bool chk=0;
	while(N>=2){
		if(arr[N-1]<arr[N])	chk=1;
		else	chk=0;
		if(chk){
			while(arr[N-1]<arr[N]){
				N--;
				if(N==1)	break;
			}
			N--;
			ans++;
		}
		else{
			while(arr[N-1]>arr[N]){
				N--;
				if(N==1)	break;
			}
			N--;
			ans++;
		}
	}
	if(N==1)	ans++;
	cout<<ans<<"\n";
	return 0;
}
