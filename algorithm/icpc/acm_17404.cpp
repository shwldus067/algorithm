#include<iostream>
using namespace std;
int const inf=1000*1000+1;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int N, ans;
	cin>>N;
	int A[N][3];
	int res[N][3];
	for(int i=0;i<N;i++){
		for(int j=0;j<3;j++){
			cin>>A[i][j];
		}
	}
	
	ans=inf;
	for(int c=0;c<3;c++){
		for(int i=0;i<3;i++){
			if(i==c)	res[0][i]=A[0][i];
			else	res[0][i]=inf;
		}
		for(int i=1;i<N;i++){
			res[i][0]=min(res[i-1][1], res[i-1][2])+A[i][0];
			res[i][1]=min(res[i-1][0], res[i-1][2])+A[i][1];
			res[i][2]=min(res[i-1][0], res[i-1][1])+A[i][2];
		}
		for(int i=0;i<3;i++){
			if(i==c)	continue;
			ans=min(ans, res[N-1][i]);
		}
	}
	cout<<ans<<"\n";
	return 0;
}
