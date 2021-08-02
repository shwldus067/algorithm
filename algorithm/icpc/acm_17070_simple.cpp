#include<iostream>
using namespace std;
int N, arr[16][16], res[16][16][3];
int d[3]={2, 2, 3}, dd[3][3]={{0, 2}, {1, 2}, {0, 1, 2}};
int dr[3][3]={{0, 1}, {1, 1}, {0, 1, 1}};
int dc[3][3]={{1, 1}, {0, 1}, {1, 0, 1}};
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	for(int i=0;i<N;++i){
		for(int j=0;j<N;++j){
			cin>>arr[i][j];
		}
	}
	for(int j=1;j<N && !arr[0][j];++j){
		res[0][j][0]=1;
	}
	for(int i=1;i<N;++i){
		for(int j=1;j<N;++j){
			if(arr[i][j])	continue;
			if(res[i][j-1][0])	res[i][j][0]+=res[i][j-1][0];
			if(res[i][j-1][2])	res[i][j][0]+=res[i][j-1][2];
			if(res[i-1][j][1])	res[i][j][1]+=res[i-1][j][1];
			if(res[i-1][j][2])	res[i][j][1]+=res[i-1][j][2];
			if(!arr[i-1][j] && !arr[i][j-1]){
				res[i][j][2]+=res[i-1][j-1][0];
				res[i][j][2]+=res[i-1][j-1][1];
				res[i][j][2]+=res[i-1][j-1][2];
			}
		}
	}
	cout<<res[N-1][N-1][0]+res[N-1][N-1][1]+res[N-1][N-1][2]<<"\n";
	return 0;
}
