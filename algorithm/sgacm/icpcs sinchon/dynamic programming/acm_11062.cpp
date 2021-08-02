#include<iostream>
using namespace std;
int T, N, arr[1000], ans, d[1000][1000][2][2];
void sol(int s, int e, int t){
	if(s+1==e){
		if(arr[s]>arr[e]){
			d[s][e][t][t]=arr[s];
			d[s][e][t][t^1]=arr[e];
		}
		else{
			d[s][e][t][t]=arr[e];
			d[s][e][t][t^1]=arr[s];
		}
		return;
	}
	int &ret1=d[s][e][t][t], &ret2=d[s][e][t][t^1];
	if(ret1!=-1)	return;
	sol(s+1, e, t^1);
	sol(s, e-1, t^1);
	int first=d[s+1][e][t^1][t]+arr[s];
	int second=d[s][e-1][t^1][t]+arr[e];
	if(first<second){
		ret1=second;
		ret2=d[s][e-1][t^1][t^1];
	}
	else{
		ret1=first;
		ret2=d[s+1][e][t^1][t^1];
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;++i)	cin>>arr[i];
		fill(&d[0][0][0][0], &d[N-1][N-1][1][2], -1);
		sol(0, N-1, 0);
		cout<<d[0][N-1][0][0]<<"\n";
	}
	return 0;
}
