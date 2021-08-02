#include<iostream>
using namespace std;
long long ans[30][30];
long long comb(int m, int n){
	if(n==0 || m==n){
		ans[m][n]=1;
		return 1;
	}
	if(ans[m][n])	return ans[m][n];
	return ans[m][n]=comb(m-1, n-1)+comb(m-1, n);
}
int main(){
	int T, M, N;
	cin>>T;
	fill(&ans[0][0], &ans[29][30], 0);
	for(int i=0;i<T;i++){
		cin>>N>>M;
		if(N>(M/2))	N=M-N;
		cout<<comb(M, N)<<"\n";
	}
	return 0;
}
