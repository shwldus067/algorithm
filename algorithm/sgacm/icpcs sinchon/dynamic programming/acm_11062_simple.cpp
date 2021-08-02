#include<iostream>
using namespace std;
int T, N;
int arr[1000], d[1000][1000];
int sol(int s, int e, int t){
	if(d[s][e]!=-1)	return d[s][e];
	int first, second;
	if(t==0){
		if(s==e)	return d[s][e]=arr[s];
		first=sol(s+1, e, t^1)+arr[s];
		second=sol(s, e-1, t^1)+arr[e];
		return d[s][e]=max(first, second);
	}
	else{
		if(s==e)	return d[s][e]=0;
		first=sol(s+1, e, t^1);
		second=sol(s, e-1, t^1);
		return d[s][e]=min(first, second);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>T;
	while(T--){
		cin>>N;
		for(int i=0;i<N;++i)	cin>>arr[i];
		fill(&d[0][0], &d[N-1][N], -1);
		cout<<sol(0, N-1, 0)<<"\n";
	}
	return 0;
}
