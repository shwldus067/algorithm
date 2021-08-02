#include<iostream>
using namespace std;
const int mod=1000000;
int N, d[100][100][100][2];
bool chk[100];
int sol(int idx, int l, int r, int t){
	if(l+r==0)	return 1;
	int &ret=d[idx][l][r][t];
	if(ret!=-1)	return ret;
	int cnt=0;
	ret=0;
	if(t){
		for(int i=idx+1;i<N;++i){
			if(!chk[i]){
				chk[i]=1;
				ret=(ret+sol(i, l+cnt, r-cnt-1, 0))%mod;
				chk[i]=0;
				++cnt;
			}
		}
	}else{
		for(int i=0;i<idx;++i){
			if(!chk[i]){
				chk[i]=1;
				ret=(ret+sol(i, cnt, l+r-cnt-1, 1))%mod;
				chk[i]=0;
				++cnt;
			}
		}
	}
	return ret;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>N;
	if(N==1){
		cout<<"1\n";
		return 0;
	}
	for(int i=0;i<N;++i){
		for(int j=0;j<=i;++j)for(int k=0;k<N-i;++k)
			d[i][j][k][0]=d[i][j][k][1]=-1;
	}
	int ans;
	chk[0]=1;
	ans=d[0][0][N-1][1]=sol(0, 0, N-1, 1);
	chk[0]=0;
	for(int i=1;i<N-1;++i){
		chk[i]=1;
		d[i][i][N-i-1][0]=sol(i, i, N-i-1, 0);
		ans=(ans+d[i][i][N-i-1][0])%mod;
		d[i][i][N-i-1][1]=sol(i, i, N-i-1, 1);
		ans=(ans+d[i][i][N-i-1][1])%mod;
		chk[i]=0;
	}
	chk[N-1]=1;
	d[N-1][N-1][0][0]=sol(N-1, N-1, 0, 0);
	chk[N-1]=0;
	ans=(ans+d[N-1][N-1][0][0])%mod;
	cout<<ans<<"\n";
	return 0;
}
