#include<iostream>
using namespace std;
typedef long long ll;
const int mod=1000000007;
int N, M, nemo[301][1<<18];
int sol(int x, int v){
	if(x==0)	return 1;
	int &ret=nemo[x][v];
	if(ret!=-1)	return ret;
	ret=0;
	int nv=v>>1;
	ret+=sol(x-1, nv);
	if(!(x%M) || !(v&1) || !(v&2) || !(v&(1<<M)))
		ret+=sol(x-1, nv|(1<<M));
	return ret%=mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N>>M;
	fill(&nemo[0][0], &nemo[300][1<<18], -1);
	if(N<M)	swap(N, M);
	cout<<sol(N*M, 0)<<"\n";
	return 0;
}
