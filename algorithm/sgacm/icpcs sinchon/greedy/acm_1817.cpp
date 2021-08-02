#include<iostream>
using namespace std;
int N, M, t;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	int ans=0, m=0;
	for(int i=0;i<N;++i){
		cin>>t;
		if(m==0){
			ans++;
			m=M;
		}
		if(t<=m){
			m-=t;
		}
		else{
			m=M-t;
			++ans;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
