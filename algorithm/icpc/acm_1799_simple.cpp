#include<iostream>
using namespace std;
int N, M, arr[20][20];
bool chk[20];
int sol(int k){
	if(k>=M)	return 0;
	int max=-1, c=k<N?0:k-N+1, r=k<N?k:N-1, ret;
	while(r>=0 && c<N){
		if(arr[r][c] && !chk[c-r+N]){
			chk[c-r+N]=1;
			ret=sol(k+2)+1;
			chk[c-r+N]=0;
			if(max<ret)	max=ret;
		}
		r--;
		c++;
	}
	if(max<0)	max=sol(k+2);
	return max;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	int t;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>arr[i][j];
	M=N+N-1;
	cout<<sol(0)+sol(1)<<"\n";
	return 0;
}
