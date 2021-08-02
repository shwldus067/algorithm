#include<iostream>
using namespace std;
int N, M, K;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M>>K;
	int max=0, cur;
	while(K--){
		N<(M<<1)?M--:N--;
	}
	cout<<(N<(M<<1)?(N>>1):M)<<"\n";
	return 0;
}
