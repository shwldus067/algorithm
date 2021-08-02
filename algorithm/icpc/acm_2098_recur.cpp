#include<iostream>
using namespace std;
int N, dp[1<<16][17], w[17][17], last;
int tsp(int visit, int cur){
	if(visit==last){
		if(!w[cur][0])	return 1e9;
		return w[cur][0];
	}
	int &ret=dp[visit][cur];
	if(ret)	return ret;
	ret=1e9;
	for(int i=0;i<N;++i){
		if(visit&(1<<i))	continue;
		if(!w[cur][i])	continue;
		ret=min(ret, tsp(visit|(1<<i), i)+w[cur][i]);
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)	cin>>w[i][j];
	last=(1<<N)-1;
	cout<<tsp(1, 0)<<"\n";
	return 0;
}
