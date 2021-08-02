#include<iostream>
using namespace std;
int N, M;
long long res;
int arr[1000][1000];
int row[1000], col[1000];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>N>>M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin>>arr[i][j];
			row[i]+=arr[i][j];
			col[j]+=arr[i][j];
		}
	}
	for(int i=1;i<N-1;i++)	res+=(long long)row[i];
	for(int j=1;j<M-1;j++)	res+=(long long)col[j];
	res<<=1;
	res+=(long long)arr[0][0]+arr[N-1][0]+arr[0][M-1]+arr[N-1][M-1];
	long long r1, r2, c1, c2, tp, tmp, chg;
	r1=row[0]*2-arr[0][0]-arr[0][M-1];
	r2=row[N-1]*2-arr[N-1][0]-arr[N-1][M-1];
	c1=col[0]*2-arr[0][0]-arr[N-1][0];
	c2=col[M-1]*2-arr[0][M-1]-arr[N-1][M-1];
	tmp=res;
	for(int i=1;i<N-1;i++){
		tp=(long long)row[i]*2-arr[i][0]-arr[i][M-1];
		chg=tmp-tp+r1;
		res=res>chg ? res:chg;
		chg=tmp-tp+r2;
		res=res>chg ? res:chg;
	}
	for(int j=1;j<M-1;j++){
		tp=(long long)col[j]*2-arr[0][j]-arr[N-1][j];
		chg=tmp-tp+c1;
		res=res>chg ? res:chg;
		chg=tmp-tp+c2;
		res=res>chg ? res:chg;
	}
	cout<<res<<"\n";
	return 0;
}
