#include<iostream>
using namespace std;
#define MAX 100001
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	char A[100001], B[100001], C[100001];
	cin>>N>>A>>B;
	int ans=MAX;
	for(int k=0;k<2;++k){
		int cnt=0;
		for(int i=0;i<N;++i)	C[i]=A[i];
		C[0]=k+'0';
		if(C[0]!=A[0]){
			C[1]=C[1]=='1'?'0':'1';
			++cnt;
		}
		for(int i=1;i<N;++i){
			if(B[i-1]!=C[i-1]){
				C[i-1]=C[i-1]=='1'?'0':'1';
				C[i]=C[i]=='1'?'0':'1';
				C[i+1]=C[i+1]=='1'?'0':'1';
				++cnt;
			}
		}
		if(B[N-1]==C[N-1]){
			ans=cnt<ans?cnt:ans;
		}
	}
	if(ans==MAX)	cout<<"-1\n";
	else	cout<<ans<<"\n";
	return 0;
}
