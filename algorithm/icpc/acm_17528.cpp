#include<iostream>
using namespace std;
typedef pair<int, int> pii;
int N, A[250], B[250];
//working with i'th job, remain work for f, which has remain
int d[250][62501][2];	//0:B, 1:A
int sol(int i, int t, int f){
	if(i==N)	return t;
	int &ret=d[i][t][f];
	if(ret!=-1)	return ret;
	ret=1e9;
	if(f){
		ret=min(ret, sol(i+1, t+A[i], 1));
		if(t>B[i])	ret=min(ret, sol(i+1, t-B[i], 1)+B[i]);
		else ret=min(ret, sol(i+1, B[i]-t, 0)+t);
	}
	else{
		if(t>A[i])	ret=min(ret, sol(i+1, t-A[i], 0)+A[i]);
		else	ret=min(ret, sol(i+1, A[i]-t, 1)+t);
		ret=min(ret, sol(i+1, t+B[i], 0));
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)	cin>>A[i]>>B[i];
	for(int i=0;i<250;++i)
		for(int j=0;j<62501;++j)
			d[i][j][0]=d[i][j][1]=-1;
	cout<<sol(0, 0, 0)<<"\n";
	return 0;
}
