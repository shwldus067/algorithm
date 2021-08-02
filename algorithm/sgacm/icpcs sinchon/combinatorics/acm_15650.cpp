#include<iostream>
using namespace std;
int N, M;
bool arr[9];
char ans[16];
void sol(int n, int k){
	if(n==M){
		cout<<ans<<"\n";
		return;
	}
	for(int i=k+1;i<=N;++i){
		if(!arr[i]){
			arr[i]=true;
			ans[n]=i+'0';
			ans[n+1]=' ';
			sol(n+2, i);
			arr[i]=false;
		}
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	M+=M;
	sol(0, 0);
	return 0;
}
